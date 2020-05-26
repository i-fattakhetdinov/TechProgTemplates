//
// Created by akhtyamovpavel on 5/1/20.
//
#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>

auto workingDir = boost::filesystem::temp_directory_path().string();

class TreeTestCase : public ::testing::Test {
protected:
    void SetUp() {
        boost::filesystem::create_directories(workingDir + "test/folder1");
        boost::filesystem::create_directories(workingDir + "test/folder2");
        boost::filesystem::ofstream(workingDir + "test/1.txt");
    }

    void TearDown() {
        boost::filesystem::remove_all(workingDir + "test");
    }
};


