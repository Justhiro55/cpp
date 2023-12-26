/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:51:03 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/19 21:05:17 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
  public:
    PhoneBook();
    ~PhoneBook();

    void ADD();
    void SEARCH();
    void EXIT() const;
    void PrintContact(void);

  private:
    int   current_index;
		int		index;
    Contact contacts[8];
};

#endif