//
// Created by xuyou on 19-4-2.
//
int rand7(){
    return 1;
}
int rand10() {
    int num, num2 = 11;
    while (num2 > 10) {
        num = rand7();
        while (num == 4) {
            num = rand7();
        }
        if (num < 4)
            num2 = 7 + rand7();
        else
            num2 = rand7();
    }
    return num2;
}