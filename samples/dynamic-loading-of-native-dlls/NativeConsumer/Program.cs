using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace NativeConsumer
{
    /// <summary>
    /// A peek into Win32 DLLs
    /// </summary>
    public static class NativeLibrary
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr LoadLibrary(string dllToLoad);

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetProcAddress(IntPtr hModule, string procedureName);

        [DllImport("kernel32.dll")]
        public static extern bool FreeLibrary(IntPtr hModule);

        public static string GetLibraryPathname(string filename)
        {
            // If 64-bit process, load 64-bit DLL
            bool is64bit = System.Environment.Is64BitProcess;

            string prefix = "Win32";

            if (is64bit)
            {
                prefix = "x64";
            }

            var lib1 = prefix + @"\" + filename;

            return lib1;
        }
    }

    public class Lib1Wrapper
    {
        // Delegate with function signature for the GetVersion function 
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.U4)]
        delegate UInt32 GetVersionDelegate(
            [OutAttribute][InAttribute] StringBuilder versionString,
            [OutAttribute] UInt32 length);


        public string GetVersion()
        {
            if (_getversion != null)
            {
                // Allocate buffer
                var size = 100;
                StringBuilder builder = new StringBuilder(size);

                // Get version string
                _getversion(builder, (uint)size);

                // Return string
                return builder.ToString();
            }

            return "";
        }

        public Lib1Wrapper(string filename)
        {
            // Get 32-bit or 64-bit library directory
            var lib1 = NativeLibrary.GetLibraryPathname("Lib1.dll");
            _dllhandle = NativeLibrary.LoadLibrary(lib1);
            
            // Handle error loading
            if (_dllhandle == IntPtr.Zero)
            {
                return;
            }

            // Get handle to GetVersion method in Lib1.dll
            var get_version_handle = NativeLibrary.GetProcAddress(_dllhandle, "GetVersion");

            // If successful, load function pointer
            if (get_version_handle != IntPtr.Zero)
            {
                _getversion = (GetVersionDelegate)Marshal.GetDelegateForFunctionPointer(
                    get_version_handle, 
                    typeof(GetVersionDelegate));
            }

        }

        ~Lib1Wrapper()
        {
            // Free resources. 
            // Probably should use SafeHandle or some similar class, 
            // but this will do for now.
            NativeLibrary.FreeLibrary(_dllhandle);
        }

        // Handles and delegates
        IntPtr _dllhandle = IntPtr.Zero;
        GetVersionDelegate _getversion = null;

    }

    class Program
    {

        static void Main(string[] args)
        {
            // Load library wrapper
            Lib1Wrapper lib1 = new Lib1Wrapper("Lib1.dll");

            // Get version, 32-bit or 64-bit
            var version = lib1.GetVersion();

            // Print version string
            Console.WriteLine("Version:");
            Console.WriteLine(version);
            Console.WriteLine("Done library test");
        }
    }
}

