// This file compiles in both Visual Studio 2010 (and newer) and G++ with C++11.

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
        void setEntityHandler( Entity & entity );

        MessageHandler  m_MessageHandler;

};

class Entity
{
    public:


        template<typename MSG>
        void setComponentHandler( Component & component );

        MessageHandler  m_MessageHandler;
};


// Implementation of circular dependencies
template<typename MSG>
void Component::setEntityHandler( Entity & entity )
{
    auto handleMsg = [&] ( const MSG & msg )
    {
        /* do stuff */
    };

    entity.m_MessageHandler.setHandler<MSG>( handleMsg );
}

template<typename MSG>
void Entity::setComponentHandler( Component & component )
{
    auto handleMsg = [&] ( const MSG & msg )
    {
        /* do stuff */
    };

    component.m_MessageHandler.setHandler<MSG>( handleMsg );
}

// Main
int main()
{
    Component c;
    Entity e;

    e.setComponentHandler<MsgDouble>(c);

	return 0;
}

