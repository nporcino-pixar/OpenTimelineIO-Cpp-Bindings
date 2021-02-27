#include "OpenTimelineIO.hpp"

void reference()
{
    otio::ErrorStatus errorStatus;
    ez::Timeline timeline("ReferenceTimeline");
    ez::Track track("Boards", nullptr, "Video");
    otio::RationalTime start{0,24};
    otio::RationalTime duration{75*24+4,24};
    otio::TimeRange movie_timerange{start, duration};
    ez::ExternalReference mr("/Users/nporcino/Projects/movie.mov", &movie_timerange);
#if 0
    otio::Clip cl("test clip1", mr.external_reference(), &movie_timerange);
    track.insert_child(0, cl, errorStatus);
    otio::Stack stack(nullptr, nullptr, nullptr, nullptr, nullptr);
    stack.insert_child(nullptr, track, errorStatus);
    timeline.set_tracks(stack);
    timeline.to_json_file("~/test.otio", errorStatus, 4);
#endif
}

int main()
{
    return 0;
}
