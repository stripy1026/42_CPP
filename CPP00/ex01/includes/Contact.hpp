#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <string>

class Contact
{
  private:
    std::string m_fields[5];
    const static std::string m_fields_name[5];
    enum e_field
    {
        first_name = 0,
        last_name,
        nickname,
        phone_number,
        darkest_secret
    };

  public:
    Contact();
    virtual ~Contact();

    void make_info();
    void show_status();
};

#endif
