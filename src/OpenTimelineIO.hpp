
#include <opentimelineio/version.h>
#include <opentimelineio/clip.h>
#include <opentimelineio/externalReference.h>
#include <opentimelineio/gap.h>
#include <opentimelineio/serializableObject.h>
#include <opentimelineio/timeline.h>
#include <opentimelineio/track.h>
#include <opentimelineio/transition.h>
#include <memory>

namespace otio = opentimelineio::OPENTIMELINEIO_VERSION;
namespace ez
{
    class Timeline
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Timeline>> _timeline;
    public:
        explicit Timeline(char const*const name_,
                          opentime::RationalTime* start_time = nullptr,
                          otio::AnyDictionary const* metaData_ = nullptr)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            otio::AnyDictionary temp;
            otio::AnyDictionary const* metaData = metaData_? metaData_ : &temp;
            otio::optional<opentime::RationalTime> t;
            if (start_time)
                t = *start_time;
            otio::Timeline* timeline = new otio::Timeline(name, t, *metaData);
            _timeline = std::make_unique<otio::SerializableObject::Retainer<otio::Timeline>>(timeline);
        }
        ~Timeline() = default;

        otio::SerializableObject::Retainer<otio::Timeline> timeline() const 
        {
            return otio::SerializableObject::Retainer<otio::Timeline>(*_timeline.get());
        }
    };

    class Stack
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Stack>> _stack;
    public:

        explicit Stack(char const*const name_,
                       opentime::TimeRange* range,
                       otio::AnyDictionary const* metaData_ = nullptr)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            otio::AnyDictionary temp;
            otio::AnyDictionary const* metaData = metaData_? metaData_ : &temp;
            otio::optional<opentime::TimeRange> tr;
            if (range)
                tr = *range;
            otio::Stack* s = new otio::Stack(name, tr, *metaData);
            _stack = std::make_unique<otio::SerializableObject::Retainer<otio::Stack>>(s);
        }

        explicit Stack(otio::SerializableObject::Retainer<otio::Stack> s)
        {
            _stack = std::make_unique<otio::SerializableObject::Retainer<otio::Stack>>(s.value);
        }

        static Stack* construct_if(otio::SerializableObject::Retainer<otio::Item> i)
        {
            if (i.value->schema_name() == otio::Stack::Schema::name)
            {
                otio::SerializableObject::Retainer<otio::Stack>* c = reinterpret_cast<otio::SerializableObject::Retainer<otio::Stack>*>(&i);
                Stack* stack = new Stack(*c);
                return stack;
            }
            return nullptr;
        }

        ~Stack() = default;

        otio::SerializableObject::Retainer<otio::Stack> stack() const 
        {
            return otio::SerializableObject::Retainer<otio::Stack>(*_stack.get());
        }
    };

    class Track
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Track>> _track;
    public:
        explicit Track(char const*const name_,
                       opentime::TimeRange* range,
                       char const*const kind_,
                       otio::AnyDictionary const* metaData_ = nullptr)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            std::string kind;
            if (kind_)
                name.assign(kind_);
            otio::AnyDictionary temp;
            otio::AnyDictionary const* metaData = metaData_? metaData_ : &temp;
            otio::optional<opentime::TimeRange> tr;
            if (range)
                tr = *range;
            otio::Track* t = new otio::Track(name, tr, kind, *metaData);
            _track = std::make_unique<otio::SerializableObject::Retainer<otio::Track>>(t);
        }

        explicit Track(otio::SerializableObject::Retainer<otio::Track> s)
        {
            _track = std::make_unique<otio::SerializableObject::Retainer<otio::Track>>(s.value);
        }

        static Track* construct_if(otio::SerializableObject::Retainer<otio::Item> i)
        {
            if (i.value->schema_name() == otio::Track::Schema::name)
            {
                otio::SerializableObject::Retainer<otio::Track>* c = reinterpret_cast<otio::SerializableObject::Retainer<otio::Track>*>(&i);
                Track* track = new Track(*c);
                return track;
            }
            return nullptr;
        }

        ~Track() = default;

        otio::SerializableObject::Retainer<otio::Track> track() const 
        {
            return otio::SerializableObject::Retainer<otio::Track>(*_track.get());
        }
    };

    class ExternalReference
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::ExternalReference>> _ref;
    public:
        explicit ExternalReference(char const*const name_,
                       opentime::TimeRange* range,
                       otio::AnyDictionary const* metaData_ = nullptr)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            otio::AnyDictionary temp;
            otio::AnyDictionary const* metaData = metaData_? metaData_ : &temp;
            otio::optional<opentime::TimeRange> tr;
            if (range)
                tr = *range;
            otio::ExternalReference* t = new otio::ExternalReference(name, tr, *metaData);
            _ref = std::make_unique<otio::SerializableObject::Retainer<otio::ExternalReference>>(t);
        }
        ~ExternalReference() = default;

        otio::SerializableObject::Retainer<otio::ExternalReference> externalReference() const 
        { 
            return otio::SerializableObject::Retainer<otio::ExternalReference>(*_ref.get());
        }
    };

    class Clip
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Clip>> _clip;
    public:
        explicit Clip(char const*const name_,
                      otio::MediaReference* mr,
                      opentime::TimeRange* range,
                      otio::AnyDictionary const* metaData_ = nullptr)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            otio::AnyDictionary temp;
            otio::AnyDictionary const* metaData = metaData_? metaData_ : &temp;
            otio::optional<opentime::TimeRange> tr;
            if (range)
                tr = *range;
            otio::Clip* t = new otio::Clip(name, mr, tr, *metaData);
            _clip = std::make_unique<otio::SerializableObject::Retainer<otio::Clip>>(t);
        }

        explicit Clip(otio::SerializableObject::Retainer<otio::Clip> c)
        {
            _clip = std::make_unique<otio::SerializableObject::Retainer<otio::Clip>>(c.value);
        }

        ~Clip() = default;

        static Clip* construct_if(otio::SerializableObject::Retainer<otio::Item> i)
        {
            if (i.value->schema_name() == otio::Clip::Schema::name)
            {
                otio::SerializableObject::Retainer<otio::Clip>* c = reinterpret_cast<otio::SerializableObject::Retainer<otio::Clip>*>(&i);
                Clip* clip = new Clip(*c);
                return clip;
            }
            return nullptr;
        }

        otio::SerializableObject::Retainer<otio::Clip> clip() const 
        { 
            return otio::SerializableObject::Retainer<otio::Clip>(*_clip.get());
        }
    };

    class Gap
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Gap>> _gap;
    public:
        explicit Gap(char const*const name_,
                     const opentime::TimeRange& range)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            otio::Gap* t = new otio::Gap(range, name);
            _gap = std::make_unique<otio::SerializableObject::Retainer<otio::Gap>>(t);
        }

        explicit Gap(otio::SerializableObject::Retainer<otio::Gap> c)
        {
            _gap = std::make_unique<otio::SerializableObject::Retainer<otio::Gap>>(c.value);
        }

        ~Gap() = default;

        static Gap* construct_if(otio::SerializableObject::Retainer<otio::Item> i)
        {
            if (i.value->schema_name() == otio::Gap::Schema::name)
            {
                otio::SerializableObject::Retainer<otio::Gap>* c = reinterpret_cast<otio::SerializableObject::Retainer<otio::Gap>*>(&i);
                Gap* gap = new Gap(*c);
                return gap;
            }
            return nullptr;
        }

        otio::SerializableObject::Retainer<otio::Gap> gap() const 
        { 
            return otio::SerializableObject::Retainer<otio::Gap>(*_gap.get());
        }
    };

    class Transition
    {
        std::unique_ptr<otio::SerializableObject::Retainer<otio::Transition>> _transition;
    public:
        explicit Transition(char const*const name_, char const*const transition_type_,
                     const opentime::RationalTime& in_offset, const opentime::RationalTime& out_offset)
        {
            std::string name;
            if (name_)
                name.assign(name_);
            std::string transition_type;
            if (transition_type_)
                transition_type.assign(transition_type_);
            otio::Transition* t = new otio::Transition(name, transition_type, in_offset, out_offset);

            _transition = std::make_unique<otio::SerializableObject::Retainer<otio::Transition>>(t);
        }

        explicit Transition(otio::SerializableObject::Retainer<otio::Transition> c)
        {
            _transition = std::make_unique<otio::SerializableObject::Retainer<otio::Transition>>(c.value);
        }

        ~Transition() = default;

        static Transition* construct_if(otio::SerializableObject::Retainer<otio::Item> i)
        {
            if (i.value->schema_name() == otio::Transition::Schema::name)
            {
                otio::SerializableObject::Retainer<otio::Transition>* c = reinterpret_cast<otio::SerializableObject::Retainer<otio::Transition>*>(&i);
                Transition* transition = new Transition(*c);
                return transition;
            }
            return nullptr;
        }

        otio::SerializableObject::Retainer<otio::Transition> transition() const 
        { 
            return otio::SerializableObject::Retainer<otio::Transition>(*_transition.get());
        }
    };
}
