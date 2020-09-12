#include <array>
#include <iostream>


template <int N>
constexpr int det(const std::array<std::array<int, N>, N> &a) {

    if constexpr (N == 0) {
		return 0;
	} else if constexpr (N == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    } else if constexpr (N == 1) {
        return a[0][0];
    } else {
    	int sign = 1;
    	int deter = 0;
    	for (int i = 0; i < N; i++) {
    		std::array<std::array<int, N - 1>, N - 1> B;
    		for(int k = 1; k < N; k++) {
    			int flg = 0;
				for (int j = 0; j < i; j++) {
				    B[j][k - 1] = a[j][k];
                }
                for (int j = i + 1; j < N; j++) {
                    B[j - 1][k - 1] = a[j][k];
                }
			}
        	deter += a[i][0] * sign * det<N - 1>(B);
    	    sign *= -1;
    	}

    	return deter;
    }
}

int main() {
    constexpr std::array<std::array<int, 3>, 3> A = {{
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 7}
    }};
    constexpr std::array<std::array<int, 2>, 2> B = {{
        {0, 1},
        {1, 2}
    }};

    constexpr std::array<std::array<int, 4>, 4> C = {{
        {2, 50, 53, 11},
        {4, 7, 3, 10}, 
        {2, 3, -121, 3},
        {6, -20, 0, 1}
    }};
    constexpr int res_a = det<3>(A);
    constexpr int res_b = det<2>(B);
    constexpr int res_c = det<4>(C);
    
    std::cout << res_a << std::endl;
    std::cout << res_b << std::endl;
    std::cout << res_c << std::endl;
}
