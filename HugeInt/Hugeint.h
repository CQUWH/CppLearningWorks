/*
 * Hugeint.h
 *
 *  Created on: 2019��4��24��
 *      Author: bully
 */

#ifndef HUGEINT_H_
#define HUGEINT_H_

#include <iostream>
using namespace std;
const int MAX = 50;

class HugeInt
{
private:
      char number[MAX];  // ��ֵ
      int len;  // ����
      bool flag;  // ����

public:
      // ���ߺ���
      static void reverse(char number[]);
      void setValue(const char *number);

      // ���캯��
      HugeInt();
      HugeInt(const int number);
      HugeInt(const char *number);

      HugeInt abs();    // ����ֵ

      // ���ظ�ֵ�����
      HugeInt operator=(const HugeInt &other);

      // ���ص�Ŀ-
      HugeInt operator-();

      // ���رȽ�����
      bool operator<(const HugeInt other);
      bool operator>(const HugeInt other);
      bool operator<=(const HugeInt other);
      bool operator>=(const HugeInt other);
      bool operator==(const HugeInt other);

      // ����+
      HugeInt operator+(const HugeInt &other);
      HugeInt operator+(const int other);
      HugeInt operator+(const char *other);

      // ����˫Ŀ-
      HugeInt operator-(const HugeInt &other);
      HugeInt operator-(const int other);
      HugeInt operator-(const char *other);

      // ����<< >>
      friend ostream &operator<<(ostream &os, const HugeInt &self);
      friend istream &operator>>(istream &is, HugeInt &self);
};

#endif /* HUGEINT_H_ */
