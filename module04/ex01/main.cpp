#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Dog と Cat のオブジェクトを作成
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();

    // 初期状態のアイデアを表示
    std::cout << "Dog1's first idea: " << dog1->getBrainIdea(0) << std::endl;
    std::cout << "Cat1's first idea: " << cat1->getBrainIdea(0) << std::endl;

    // Dog と Cat のオブジェクトのコピーを作成
    Dog* dog2 = new Dog(*dog1);
    Cat* cat2 = new Cat(*cat1);

    // コピーされたオブジェクトのアイデアを変更
    dog2->setBrainIdea(0, "Dog2's new idea");
    cat2->setBrainIdea(0, "Cat2's new idea");

    // 元のオブジェクトとコピーされたオブジェクトのアイデアを表示して、深いコピーを確認
    std::cout << "After modification:" << std::endl;
    std::cout << "Dog1's first idea: " << dog1->getBrainIdea(0) << std::endl;
    std::cout << "Dog2's first idea: " << dog2->getBrainIdea(0) << std::endl;
    std::cout << "Cat1's first idea: " << cat1->getBrainIdea(0) << std::endl;
    std::cout << "Cat2's first idea: " << cat2->getBrainIdea(0) << std::endl;

    // オブジェクトの削除
    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;

    return 0;
}


// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
