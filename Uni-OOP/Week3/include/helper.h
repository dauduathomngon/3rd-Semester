#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#endif

namespace helper
{
/* https://stackoverflow.com/questions/306533/how-do-i-get-a-list-of-files-in-a-directory-in-c */
inline void GetFilesInDirectory(std::vector<std::string>& out, const std::string& directory)
{
#ifdef __WIN32
    HANDLE dir;
    WIN32_FIND_DATAA file_data;

    if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
        return; /* No files found */

    do {
        const string file_name = file_data.cFileName;
        const string full_file_name = directory + "/" + file_name;
        const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

        if (file_name[0] == '.')
            continue;

        if (is_directory)
            continue;

        out.push_back(full_file_name);
    } while (FindNextFile(dir, &file_data));

    FindClose(dir);
#else
    DIR *dir;
    class dirent *ent;
    class stat st;

    dir = opendir(directory.c_str());
    while ((ent = readdir(dir)) != NULL) {
        const std::string file_name = ent->d_name;
        const std::string full_file_name = directory + "/" + file_name;

        if (file_name[0] == '.')
            continue;

        if (stat(full_file_name.c_str(), &st) == -1)
            continue;

        const bool is_directory = (st.st_mode & S_IFDIR) != 0;

        if (is_directory)
            continue;

        out.push_back(full_file_name);
    }
    closedir(dir);
#endif
} 

inline bool IsFileExists(const std::string& file)
{
    std::ifstream input(file);
    return input.good();
}
 
/* https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c */
inline std::string GetCurrentTime()
{
    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

} // helper


#endif // HELPER_H