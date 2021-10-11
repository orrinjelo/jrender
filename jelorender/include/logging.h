#pragma once

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/algorithm/string.hpp>

#define LOG_B(X) BOOST_LOG_TRIVIAL(X) 

namespace logging = boost::log;

void init_logging(std::string verbosity);
