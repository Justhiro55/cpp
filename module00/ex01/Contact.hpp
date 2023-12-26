/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:52:08 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/26 16:30:07 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
public:
  Contact();
  ~Contact();

  bool show_db_row(int index) const;
  void AddContent();
  void AddContent_max();
  void PrintAllContact(void);
  void PrintShortContact(void);
  std::string getShortStr(std::string str);
  void copy_contacts(Contact contact);
  Contact new_contact();

private:
  std::string lastname;
  std::string firstname;
  std::string number;
  std::string nickname;
  std::string darkestsecret;
};

#endif