/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:03:37 by flo               #+#    #+#             */
/*   Updated: 2024/09/23 08:06:07 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\ntest1:\n" << std::endl;

		Dog doggy, doggy_copy(doggy);

		for (Dog* d : {&doggy, &doggy_copy})
			std::cout << d->getBrain() << " "
				<< d->getBrain()->getIdeas(0) << std::endl;

		doggy.getBrain()->setIdeas(0, "food");

		Dog dog2;

		dog2.getBrain()->setIdeas(0, "food");

		doggy = dog2; //test if the old brain is deleted

		for (Dog* d : {&doggy, &doggy_copy})
			std::cout << d->getBrain() << " "
				<< d->getBrain()->getIdeas(0) << std::endl;

		Cat* kitty = new Cat(), *kitty_copy = new Cat(*kitty);

		for (Cat* c : {kitty, kitty_copy})
			std::cout << c->getBrain() << " "
			<< c->getBrain()->getIdeas(0) << std::endl;

		kitty->getBrain()->setIdeas(0, "chill");

		for (Cat* c : {kitty, kitty_copy})
			std::cout << c->getBrain() << " "
				<< c->getBrain()->getIdeas(0) << std::endl;

		delete kitty;
		delete kitty_copy;
	}
	{
		std::cout << "\ntest2:\n" << std::endl;

		Animal *tab[5] = { new Dog(), new Cat(),
			new Dog(), new Cat(), new Dog() };

		for (int a = 0; a < 5; ++a)
			tab[a]->makeSound();

		for (int a = 0; a < 5; ++a)
			delete tab[a];

		delete new Dog();
		delete new Cat();
	}
	{
		std::cout << "\ntest3:\n" << std::endl;

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;

		return (0);
		return (0);
	}
}
