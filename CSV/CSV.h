//
// Created by bully on 2019/5/14.
//

#ifndef CSV_CSV_H
#define CSV_CSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class CSV {
private:
    std::vector<std::vector<std::string>> file; // �����ļ�����������
    std::string filename;						// �����ļ���
    int row;									// �����ļ�����
    int col;									// �����ļ�����
public:
    CSV();
    CSV(std::string filename);
    std::vector<std::vector<std::string>> &getFile(); // ��ô洢�ļ����ݵ�vector�����ص������ã�����ֱ���޸ģ�
    int getRow();
    int getCol();
    void openFile(std::string filename); // ��ȡ�ļ����빹�캯����ͬ
    void saveCSV();						 // �����ļ�
};


#endif //CSV_CSV_H
