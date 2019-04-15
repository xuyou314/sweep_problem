#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class HMM{
private:
    int N;		/* number of states;  Q={1,2,...,N} 隐藏状态的个数*/
    int M; 		/* number of observation symbols; V={1,2,...,M} 观测状态的个数*/
    vector<vector<double>> A;	/* A[1..N][1..N]. a[i][j] is the transition prob
			   of going from state i at time t to state j
			   at time t+1 隐藏状态之间的转移概率*/
    vector<vector<double>> B;	/* B[1..N][1..M]. b[j][k] is the probability of
			   of observing symbol k in state j 隐藏状态到观测状态的转移概率分布*/
    vector<double> pi;	/* pi[1..N] pi[i] is the initial state distribution. 初始化概率分布*/

public:
    /**
     * 所有下标都是从1开始的
     */
    HMM(int n, int m, vector<vector<double>> AA, vector<vector<double>> BB, vector<double> PI ):
            N(n),M(m),A(AA),B(BB),pi(PI){}

//    void __init__(int n, int m, vector<vector<double>> A, vector<vector<double>> B, vector<double> pi){
//        this->N = n;
//        this->M = m;
//
//        this->A = A;
//        this->B = B;
//        this->pi = pi;
//    }
    /**
     * 前向算法：
     * 具体见《统计学习方法》P175页
     * 求前向概率：给定隐马尔科夫模型λ，定义到时刻t部分观察序列为o1,o2...ot，且时刻t的状态为qi的概率为前向概率
     *
     *  通过前向概率可以递推的求得前向概率α_t(i)和观察序列概率P(o|λ)
     */
    void forward(int T, const vector<int> O,vector<vector<double>>& alpha, double* prob){
        /**
         * 初始化
         */
        for(int i=1; i<=N; i++)
            alpha[1][i] = pi[i]*B[i][1];

        /**
         * 递推
         */
        for(int t=1; t<T; t++){
            for(int i=1; i<=N; i++) {
                double sum = 0.0;
                for (int j = 1; j <= N; j++)
                    sum += alpha[t][j] * A[j][i];
                alpha[t+1][i] = sum * B[i][O[t+1]];
            }
        }

        /**
         * 终止
         */
        *prob = 0.0;
        for(int i=1; i<= N; i++)
            *prob += alpha[T][i];
    }

    /**
     * 后向算法
     * 后向概率：
     * 给定隐马尔科夫模型λ，定义时刻t的状态为qi的概率下，从t+1到T部分观察序列为o_t+1,o_t+2...o_T
     *
     *  通过前向概率可以递推的求得后向概率β_t(i)和观察序列概率P(o|λ)
     */
    void backward(int T, vector<int> O, vector<vector<double>>& beta, double* prob){
        //初始化，最终时刻的所有状态都设为1
        for(int i=1; i<=N; i++)
            beta[T][1] = 1;

        /**
         * 递推计算beta
         */
        for(int t=T-1; t>0; t--){
            for(int i=1; i<=N; i++){
                beta[t][i] = 0;
                for(int j=1; j<=N; j++){
                    beta[t][i] += A[i][j] *B[j][O[t+1]] * beta[t+1][j];
                }
            }
        }

        /**
         * 计算概率
         */
        *prob = 0;
        for(int i=1; i<=N; i++){
            *prob += pi[i] * B[i][O[1]] * beta[1][i];
        }
    }

    void Viterbi(int T, vector<int> O, vector<vector<double>>& delta,
                 vector<vector<int>>& psi, vector<int>& path, double* prob){
        /**
         * 初始化
         */

        for(int i=1; i<=N; i++){
            delta[1][i] = pi[i]*B[i][O[1]];
            psi[1][i] = 0;
        }

        /**
         * 递推
         */
        for(int t=2; t<=T; t++){
            for(int i=1; i<=N; i++){
                double maxDelta = 0.0;
                int index = 1;
                for(int j=1; j<=N; j++){
                    if(maxDelta < delta[t-1][j] * A[j][i]){
                        maxDelta = delta[t-1][j] * A[j][i];
                        index = j;
                    }
                }
                delta[t][i] = maxDelta * B[i][O[t]];
                psi[t][i] = index;
            }
        }

        /**
         *  终止
         */

        *prob = 0;
        path[T] = 1;
        for(int i=1; i<=N; i++){
            if(*prob < delta[T][i]) {
                *prob = delta[T][i];
                path[T] = i;
            }
        }

        /**
         * 最优路径回溯
         */

        for(int t = T-1; t>0; t--){
            path[t] = psi[t+1][path[t+1]];
        }
    }
};


/**
 * 统计学习方法中前向概率计算例题
 */


void testForward(){
    unsigned int n = 4;
    unsigned int m = 5;
    vector<vector<double>> A(n+1, vector<double>(n+1,0.0));
    vector<vector<double>> B(n+1, vector<double>(m+1,0.0));
    vector<double> pi(n+1,0.0);

    cin >> pi[1] >> pi[2] >> pi[3] >> pi[4];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> B[i][j];
        }
    }
    char tt;
    vector<int> O = {0};
    while((tt=getchar())!=' '){
//        if(tt=='\r')
//            break;
        if(tt=='S'){
            O.push_back(1);
        }
        else {
            O.push_back(tt-'A'+2);
        }
    }

    double prob = 0.0;

    HMM hmm(n,m,A,B,pi);


    unsigned int T = O.size()-1;

    vector<vector<double>> alpha(T+1, vector<double>(n+1,0.0));
    hmm.forward(T, O, alpha, &prob);

    cout<<log10(prob)<<endl;
}


/**
 * 统计学习方法中Viterbi例题
 */


int main() {
    testForward();
    return 0;
}