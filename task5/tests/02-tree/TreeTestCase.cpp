//
// Created by akhtyamovpavel on 5/1/20.
//
#include "TreeTestCase.h"
#include "Tree.h"

TEST_F(TreeTestCase, InvalidArgument) {
    ASSERT_THROW(GetTree("NonExistingPath", true), std::invalid_argument);
    ASSERT_THROW(GetTree("test/1.txt", true), std::invalid_argument);
}

TEST_F(TreeTestCase, GetTreeWithoutFiles) {
    FileNode rootFolder;
    rootFolder.name = "test";
    rootFolder.is_dir = true;

    FileNode folder1;
    folder1.name = "folder1";
    folder1.is_dir = true;

    FileNode folder2;
    folder2.name = "folder2";
    folder2.is_dir = true;

    rootFolder.children.push_back(folder1);
    rootFolder.children.push_back(folder2);

    ASSERT_EQ(GetTree("test", true), rootFolder);
}

TEST_F(TreeTestCase, GetTreeWithFiles) {
    FileNode rootFolder;
    rootFolder.name = "test";
    rootFolder.is_dir = true;

    FileNode folder1;
    folder1.name = "folder1";
    folder1.is_dir = true;

    FileNode folder2;
    folder2.name = "folder2";
    folder2.is_dir = true;

    FileNode file;
    file.name = "1.txt";
    file.is_dir = false;

    rootFolder.children.push_back(folder1);
    rootFolder.children.push_back(folder2);
    rootFolder.children.push_back(file);

    ASSERT_EQ(GetTree("test", false), rootFolder);
}

TEST_F(TreeTestCase, OperatorNodeEqual) {
    FileNode node1;
    node1.name = "folder1";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "folder1";
    node2.is_dir = false;

    ASSERT_EQ(node1 == node1, true);
    ASSERT_EQ(node1 == node2, false);
}