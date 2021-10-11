#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>

#include "logging.h"
#include "Camera.h"
#include "Screen.h"
#include "Light.h"
#include "Sphere.h"
#include "Render.h"
#include "tnt_ops.h"
#include "RenderParser.h"

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768

namespace po = boost::program_options;

void init_logging(std::string verbosity)
{
    if (boost::algorithm::to_lower_copy(verbosity) == "error") {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::error
        );
    } else if (boost::algorithm::to_lower_copy(verbosity) == "warning") {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::warning
        );
    } else if (boost::algorithm::to_lower_copy(verbosity) == "debug") {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::debug
        );
    } else if (boost::algorithm::to_lower_copy(verbosity) == "trace") {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::trace
        );
    } else //if (boost::algorithm::to_lower_copy(verbosity) == "info") 
    {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::info
        );
    }
}


int main(int argc, char* argv[]) {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help",                                             "produce this help message" )
        ("input,i",     po::value<std::string>()
                          ->default_value("example.json"),   "input json file"           )
        ("output,o",    po::value<std::string>()
                          ->default_value("out.png"),        "output png file"           )
        ("verbose,v",   po::value<std::string>()
                          ->default_value("info"),           "verbosity for logging"     )
    ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    init_logging(vm["verbose"].as<std::string>());


    std::ifstream infile(vm["input"].as<std::string>());
    std::string json, str;
    while (std::getline(infile, str))
    {
      json += str;
      json.push_back('\n');
    }
    RenderParser renderp(json);
    renderp.getRender()->generate(vm["output"].as<std::string>());

    return 0;
}
