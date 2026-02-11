#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *c);
void identify(Base &c);

#endif /* BASE_HPP */
