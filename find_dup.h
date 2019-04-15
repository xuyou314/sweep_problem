//
// Created by xuyou on 19-2-27.
//

#ifndef SWEEP_PROBLEM_FIND_DUP_H
#define SWEEP_PROBLEM_FIND_DUP_H


class find_dup {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int temp;
        if(numbers == nullptr || length <= 0)
            return false;
        for(int i=0;i<length;i++){

            while(numbers[i]!=i){
                temp=numbers[i];
                if(temp==numbers[temp]){
                    *duplication=temp;
                    return true;
                }

                numbers[i]=numbers[temp];
                numbers[temp]=temp;

            }
        }
        return false;
    }
};


#endif //SWEEP_PROBLEM_FIND_DUP_H
