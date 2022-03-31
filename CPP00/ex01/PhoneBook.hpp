#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Contact;

class PhoneBook
{
private:
	Contact	contacts[8];
	int		num;
public:
	PhoneBook();
	PhoneBook(const PhoneBook &phonebook);
	virtual ~PhoneBook();
	PhoneBook &operator=(const PhoneBook &phonebook);
};

#endif