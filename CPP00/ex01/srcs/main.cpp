#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook pb;

    pb.print_startup_message();
    pb.add_contact();
    pb.display_contact();
    return (0);
}
