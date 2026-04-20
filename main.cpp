#include <iostream>
#include <exception>
#include <tuple>
/*
Exceptions
----------------
what?
how?
Own exceptions (throw)
when only option (constructors, destructors)

what for? overuse?
Lets see "Golang"-style

minus: performance
    handling exceptions is expensive, especially if they are thrown frequently. It can lead to slower execution and increased memory usage.
plus: performance (collecting all errors in one place, not having to check for errors after every function call)
    when exceptions are used properly, they can improve performance by allowing developers to handle errors in a centralized manner. This can lead to cleaner code and reduced overhead from error checking after every function call.



*/

// struct BankAccount {
//     int balance = 0;
//     int withdrawals_today = 0;

//     int withdraw(int amount){

//          if (amount > balance ){
//              throw std::runtime_error("Insufficient funds");
//          }
//          if(amount < 0){
//              throw std::invalid_argument("Amount cannot be negative");
//          }
//          if(amount > 1000){
//              throw std::out_of_range("Amount exceeds withdrawal limit");
//          }

//          if(withdrawals_today + amount > 10000){
//              throw std::out_of_range("Amount daily withdrawal limit");
//          }
//          withdrawals_today += amount;
//          balance -= amount;
//          return balance;
//     }
// };

// 1. Exceptions are overengineered in this scenario
// these are expected errors




// struct BankAccount {
//     int balance = 0;
//     int withdrawals_today = 0;


//     BankAccount(int initial_balance) : balance(initial_balance) {
//         if(initial_balance < 0){
//              throw std::invalid_argument("Initial balance cannot be negative");
//         }
//     }

//     typedef enum {
//         Ok,
//         InsufficientFunds,
//         NegativeAmount,
//         ExceedsWithdrawalLimit,
//         DailyWithdrawalLimitExceeded
//     } ErrorCode_Withdrawal;


//      ErrorCode_Withdrawal withdraw(int amount, int& new_balance){

//          if (amount > balance ){
//              return ErrorCode_Withdrawal::InsufficientFunds;
//          }
//          if(amount < 0){
//              return ErrorCode_Withdrawal::NegativeAmount;
//          }
//          if(amount > 1000){
//              return ErrorCode_Withdrawal::ExceedsWithdrawalLimit;
//          }

//          if(withdrawals_today + amount > 10000){
//              return ErrorCode_Withdrawal::DailyWithdrawalLimitExceeded;
//          }
//          withdrawals_today += amount;
//          balance -= amount;
//          new_balance = balance;
//          return ErrorCode_Withdrawal::Ok;
//     }
// };



struct BankAccount {
    int balance = 0;
    int withdrawals_today = 0;


    BankAccount(int initial_balance) : balance(initial_balance) {
        if(initial_balance < 0){
             throw std::invalid_argument("Initial balance cannot be negative");
        }
    }

    typedef enum {
        Ok,
        InsufficientFunds,
        NegativeAmount,
        ExceedsWithdrawalLimit,
        DailyWithdrawalLimitExceeded
    } ErrorCode_Withdrawal;


    // return tuple of error code and new balance
     std::tuple<ErrorCode_Withdrawal, int> withdraw(int amount ){

         if (amount > balance ){
             return std::make_tuple(ErrorCode_Withdrawal::InsufficientFunds, balance);
         }
         if(amount < 0){
             return std::make_tuple(ErrorCode_Withdrawal::NegativeAmount, balance);
         }
         if(amount > 1000){
             return std::make_tuple(ErrorCode_Withdrawal::ExceedsWithdrawalLimit, balance);
         }

         if(withdrawals_today + amount > 10000){
             return std::make_tuple(ErrorCode_Withdrawal::DailyWithdrawalLimitExceeded, balance);
         }
         withdrawals_today += amount;
         balance -= amount;
         return std::make_tuple(ErrorCode_Withdrawal::Ok, balance);
    }
};






int divide(int a, int b) {
    BankAccount account(100);
    std::tuple<BankAccount::ErrorCode_Withdrawal, int> result =  account.withdraw(50);    
    
    // auto error_code = std::get<0>(result);
    // auto new_balance = std::get<1>(result);
    // if(error_code != BankAccount::ErrorCode_Withdrawal::Ok){
    //     std::cerr << "Error withdrawing from account: " << error_code << std::endl;
    // }
    

    auto [error_code, new_balance] = result;
    
    if (b == 0) {
        throw std::invalid_argument("b cannot be zero");
    }
    return a / b;
}


void test(){
    int x = 10;
    int y = 0;


    try
    {
        int result = divide(x, y);
        std::cout << "Hello, World!" << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}



int main() {
    int x = 10;
    int y = 0;

    std::cout << "Running!" << std::endl;

    test();
    std::cout << "Ending" << std::endl;
    return 0;



    // if (test() == false){[

    // ]}
    // if(test2() == false){

    // }


    // if we use exceptions for what its supposed to be used, we can catch them in one place and handle them accordingly, 
    // instead of having to check for errors after every function call.
    // THEN EXCEPTIONS ARE MORE PERFOPRMANT
    // try{
    //     test();
    //     test2();
    // }catch (const std::exception& e){
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }


}



