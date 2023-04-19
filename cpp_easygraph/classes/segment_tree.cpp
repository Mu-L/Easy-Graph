#include "../common/common.h"

class Segment_tree_zkw {
    private:
        int tn;
    public:
        std::vector<int> t;
        std::vector<int> num;
        Segment_tree_zkw(int N){
            int size = (N+1)<<2;
            t.resize(size+1, INT_MAX);
            num.resize(size+1, 0);
        }
        void init(int N) {
            tn = 1;
            while(tn < N) tn <<= 1;
            --tn;
            for (int i = 1; i <= N; ++i)
                this->num[i + tn] = i;
        }

        void change(int p, const int &k) {
            p += tn; t[p] = k; p >>= 1;
            while (p) {
                if (t[p<<1] < t[p<<1|1]) {
                    t[p] = t[p<<1];
                    num[p] = num[p<<1];
                }
                else {
                    t[p] = t[p<<1|1];
                    num[p] = num[p<<1|1];
                }
                p >>= 1;
            }
        }
};