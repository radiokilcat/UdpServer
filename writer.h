#ifndef WRITER_H
#define WRITER_H

#include <queue>
#include <string>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class Writer
{
public:
    Writer();
    void write_to_file(const fs::path& file);
private:
    std::queue<std::string> message_queue_;
    const fs::path settings_path_;

};

#endif // WRITER_H
