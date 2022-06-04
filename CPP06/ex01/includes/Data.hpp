#ifndef _DATA_HPP_
#define _DATA_HPP_

class Data
{
  private:
    int m_value;

    Data();
    Data(const Data &src);
    Data &operator=(const Data &rhs);

  public:
    ~Data();

    Data(int value);

    int getValue() const;
};

#endif // _DATA_HPP_
