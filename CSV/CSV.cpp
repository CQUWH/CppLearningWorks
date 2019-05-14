//
// Created by bully on 2019/5/14.
//

#include "CSV.h"
using namespace std;
CSV::CSV()
{
    this->row = 0;
    this->col = 0;
}
CSV::CSV(string filename)
{
    openFile(filename);
}

void CSV::openFile(string filename)
{
    this->filename = filename;
    this->row = 0;
    this->col = 0;
    this->file.clear(); // �����ǰ����
    ifstream in_file(filename, ios::in);
    string line;        // ���浱ǰ��������
    while (getline(in_file, line))
    {
        stringstream ss(line);
        std::string temp;				   // ���浱ǰ���ڶ�ȡ����Ԫ��
        std::vector<std::string> curLine; // ���浱ǰ�е�����
        while (getline(ss, temp, ','))
        {
            curLine.push_back(temp);
        }
        this->col = curLine.size();
        this->file.push_back(curLine); // ���������д����άvector
        row++;
    }
}

void CSV::saveCSV()
{
    ofstream out_file;
    out_file.open(this->filename, ios::out); // ���ļ�
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            out_file << file[i][j];
            if (j != col - 1)
            { // ������ĩβ��д�붺��
                out_file << ',';
            }
        }
        out_file << endl; // �н���д�뻻�з�
    }
    out_file.close(); // �ر��ļ�
}

std::vector<std::vector<std::string>> &CSV::getFile()
{
    return this->file;
}

int CSV::getRow()
{
    return this->row;
}

int CSV::getCol()
{
    return this->col;
}
