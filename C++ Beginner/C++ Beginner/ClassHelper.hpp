//
//  ClassHelper.hpp
//  C++ Beginner
//
//  Created by 邹嘉睿 on 2026.03.28.
//

#ifndef ClassHelper_hpp
#define ClassHelper_hpp

#include <stdio.h>
#include <iostream>
class parent{
public:
    
    parent(){
        std::cout << "Hello from parent!" << std::endl;
    }
    
    ~parent(){
        std::cout << "parent EXIT" << std::endl;
    }
//    parent() = default;
//    ~parent() = default;
    
    
    
    int pubParentNum;
    
    

protected:
    int proParentNum;
    
    virtual const void f();

private:
    int priParentNum;
    

};

class childA : public parent{
public:
    childA(){
        std::cout << "Hello from child!" << std::endl;
    }
    
    ~childA(){
        std::cout << "childA EXIT" << std::endl;
    }
    
    const void f() override; // !can't believe it, protected can be override.

protected:
    int proChildNum;
    
private:
    int priChildNum;
    
};





#endif /* ClassHelper_hpp */
