#include <iostream>				// std::cout
#include <boost/signals2.hpp>	// boost::signals2
#include <memory>

// Typedef
typedef boost::signals2::connection connection;

// MessageId
typedef int MessageId;

// Base Message class
class MessageBase
{
    public:
        // Just go with the default constructors and destructors
        explicit MessageBase() {}
        virtual ~MessageBase() {}

    public:
        // Abstract method
        virtual MessageId getMessageId() const = 0;
};

// Templated Message class
template<MessageId ID>
class Message : public MessageBase
{
    public:
        explicit Message() :
            MessageBase()
        {

        }

        virtual ~Message() {}

    public:
        MessageId getMessageId() const
        {
            return MsgId;
        }


    public:
        // Hooray for C++11
        static const MessageId	MsgId = ID;
};

enum MessageTypes : MessageId
{
    MESSAGE_SET_POSITION,
    MESSAGE_SET_ROTATION,

    MESSAGE_ORDINAL
};

template<typename REGREQUEST,typename MSG>
class regRequest_wrapper
{
    public:
        typedef REGREQUEST	request;
        typedef MSG			msg;

    public:
        explicit regRequest_wrapper(const request & req)
            : m_Request(req)
        {

        }

        ~regRequest_wrapper()
        {

        }

    public:
        void operator()(const msg &m)
        {
            m_Request(m);
        }

    private:

        request					m_Request;

};

class opWrapper
{
    public:
        explicit opWrapper()	{}
        virtual ~opWrapper()	{}

    public:
        virtual void call(const MessageBase &msg)	= 0;
        virtual void disconnect_all_slots()			= 0;

    protected:

};



template<typename MSG>
class opWrapper_templ: public opWrapper
{
    public:
        typedef				MSG												msg;

        typedef	typename	boost::signals2::signal<void(const msg &)>		registration_manager;
        typedef	typename	registration_manager::slot_type					registration_request;
        typedef 			regRequest_wrapper<registration_request,msg>	request_wrapper;
        typedef typename	boost::signals2::connection						connection;


    public:
        connection connect( const registration_request &req )
        {
            return m_Subscribers.connect( request_wrapper(req) );
        }

        void call(const MessageBase &message)
        {
            m_Subscribers(static_cast<const msg&>(message));
        }

        void disconnect_all_slots()
        {
            m_Subscribers.disconnect_all_slots();
        }

    private:
        registration_manager	m_Subscribers;
};

class MessageHandler
{
    public:
        // Shortcut typedefs
// 		typedef	boost::signals2::signal<void(const MessageBase &)>	registration_manager;
// 		typedef	registration_manager::slot_type						registration_request;
// 		typedef std::unique_ptr<registration_manager>				registration_manager_ptr;
        typedef boost::signals2::connection							connection;

        // Define the signal handlers
        opWrapper * m_MessageHandlers[MESSAGE_ORDINAL];

    public:
        explicit MessageHandler()
        {
            for ( size_t i=0; i<MESSAGE_ORDINAL; ++i )
            {
                m_MessageHandlers[ i ] = nullptr;
            }
        }

        virtual ~MessageHandler()
        {
        }


    public:

        void operator()( const MessageBase & basemsg )
        {
            handleMessage( basemsg );
        }

        void handleMessage( const MessageBase & basemsg )
        {
            const MessageId ID = basemsg.getMessageId();

            // Find handler
            opWrapper *& handler = m_MessageHandlers[ ID ];

            if ( ! handler )
            {
                return;
            }

            // Call active handler
            handler->call(basemsg);
        }

        template<typename MSG, typename REQ>
        connection setHandler(const REQ & req)
        {
            typedef opWrapper_templ<MSG>		wrapper;

            // Get message id
            const MessageId ID = MSG::MsgId;

            // Find handler
            opWrapper *& ptr = m_MessageHandlers[ ID ];

            if( ! ptr )
            {
                ptr = new wrapper();
            }

            wrapper *handler = static_cast<wrapper*>(ptr);

            return handler->connect( req );
        }

};

class SetPositionMessage: public Message<MESSAGE_SET_POSITION>
{
    public:
        explicit SetPositionMessage() {}
        virtual ~SetPositionMessage() {}

};

class SetRotationMessage: public Message<MESSAGE_SET_ROTATION>
{
    public:
        explicit SetRotationMessage() {}
        virtual ~SetRotationMessage() {}
};

void handleSetPositionMessage( const SetPositionMessage & setposmsg )
{
    std::cout << "Set position message arrived!" << std::endl;
}

void handleSetRotationMessage(const SetRotationMessage & setposmsg)
{
    std::cout << "Set rotation message arrived!" << std::endl;
}

int test5_template_class()
{
    // Only a message handler
    MessageHandler handler;

    // Set handler for SetPositionMessage
    handler.setHandler<SetPositionMessage>( &handleSetPositionMessage );

    // Set handler for SetRotationMessage
    handler.setHandler<SetRotationMessage>( &handleSetRotationMessage );

    // Call the message handler
    handler( SetPositionMessage() );
    handler( SetRotationMessage() );

    // Output should be:
    // Lambda input value: 3.14
    // Inline lambda input value: 3.14

    return 0;
}
