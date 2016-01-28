// This file only compiles in Visual Studio 2010 newer

template<typename T>
class Message
{
    public:
        typedef T       type;

        static const int MsgId   = 0;


        explicit Message( const T & t )
            : data(t)
        {
        }


        type        data;
};

typedef Message<int>    MsgInt;
typedef Message<long>   MsgLong;
typedef Message<float>  MsgFloat;
typedef Message<double> MsgDouble;

class MessageHandler
{
    public:

        template<typename MSG, typename T>
        void setHandler( const T & msghandler )
        {
            /* do stuff */
            auto id = MSG::MsgId; // Make sure this is a message type
        }
};


// Forward declaration of classes
class Component;
class Entity;

class Component
{
    public:

        template<typename MSG>
        void setEntityHandler( Entity & entity )
        {
            auto handleMsg = [&] ( const MSG & msg )
            {
                /* do stuff */
            };

            entity.m_MessageHandler.setHandler<MSG>( handleMsg );
        }


        MessageHandler  m_MessageHandler;


};

class Entity
{
    public:


        template<typename MSG>
        void setComponentHandler( Component & component )
        {
            auto handleMsg = [&] ( const MSG & msg )
            {
                /* do stuff */
            };

            component.m_MessageHandler.setHandler<MSG>( handleMsg );
        }

        MessageHandler  m_MessageHandler;
};


int main()
{
    Component c;
    Entity e;

    e.setComponentHandler<MsgDouble>(c);

	return 0;
}

