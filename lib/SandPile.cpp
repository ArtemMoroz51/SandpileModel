#include "..\lib\SandPile.h"

int** AddStringUp(int** input_data, int m, int n) {
    int** matrix = new int* [m + 1];
    for (int i = 0; i <= m; i++) {
        matrix[i] = new int[n] {0};
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i + 1][j] = input_data[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        delete[] input_data[i];
    }
    delete[] input_data;

    return matrix;

}

int** AddStringDown(int** input_data, int m, int n) {
    int** matrix = new int* [m + 1];
    for (int i = 0; i <= m; i++) {
        matrix[i] = new int[n] {0};
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = input_data[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        delete[] input_data[i];
    }
    delete[] input_data;

    return matrix;

}
int** AddColumnLeft(int** input_data, int m, int n) {
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n + 1] {0};
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j + 1] = input_data[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        delete[] input_data[i];
    }
    delete[] input_data;

    return matrix;

}
int** AddColumnRight(int** input_data, int m, int n) {
    int** matrix = new int* [m];

    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n + 1] {0};
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = input_data[i][j];
        }
       
    }
    for (int i = 0; i < m ; i++) {
        delete[] input_data[i];

    }
   
    delete[] input_data;
    
    return matrix;

}



void SandPile(InputData input_data, Parser parser) {
    std::string str;
    bool is_stabilization = 0;
    int iter_counter = 0;
    Pile SandPile;
    SandPile.m = input_data.m;
    SandPile.n = input_data.n;
    SandPile.sand_pile = input_data.input_data;
    SandPile.number_of_iteration = 0;
    int max_iter = parser.iter;
    MyQueue my_queue;
    while ((!is_stabilization) && (max_iter == 0 || max_iter > iter_counter )) {
        iter_counter++;
        is_stabilization = 1;
        
        for (int i = 0; i < SandPile.m; i++){
            if ((SandPile.sand_pile[0][i] >= 4)) {
                SandPile.sand_pile = AddStringUp(SandPile.sand_pile, SandPile.m, SandPile.n);
                ++SandPile.m;
                break;
            }
        }
        for (int i = 0; i < SandPile.n; i++) {
            if ((SandPile.sand_pile[SandPile.m - 1][i] >= 4)) {
                SandPile.sand_pile = AddStringDown(SandPile.sand_pile, SandPile.m, SandPile.n);
                ++SandPile.m;
                break;
            }
        }
        for (int i = 0; i < SandPile.m; i++) {
            if ((SandPile.sand_pile[i][0] >= 4)) {
                SandPile.sand_pile = AddColumnLeft(SandPile.sand_pile, SandPile.m, SandPile.n);
                ++SandPile.n;
                break;
            }
        }
        for (int i = 0; i < SandPile.m; i++) {
            if ((SandPile.sand_pile[i][SandPile.n - 1] >= 4)) {
                SandPile.sand_pile = AddColumnRight(SandPile.sand_pile, SandPile.m, SandPile.n);
                ++SandPile.n;
                break;
            }
        }
        for (int i = 0; i < SandPile.m; i++) {
            for (int j = 0; j < SandPile.n; j++) {
                if ((SandPile.sand_pile[i][j] >= 4)) {
                    my_queue.add(std::make_pair(i, j));
                    is_stabilization = 0;

                }
                

            }
        }

        
        while (my_queue.size() != 0) {
            long long x = my_queue.show().first;
            long long y = my_queue.show().second;
            SandPile.sand_pile[x][y] = SandPile.sand_pile[x][y] - 4;
            SandPile.sand_pile[x][y - 1]++;
            SandPile.sand_pile[x][y + 1]++;
            SandPile.sand_pile[x + 1][y]++;
            SandPile.sand_pile[x - 1][y]++;
            my_queue.pop();
        }
        if (parser.freq != 0 && iter_counter % parser.freq == 0) {
            
            SandPile.number_of_iteration++;
            CreatFile(SandPile, parser.save_pictures);
        }
        
    
       
    }
    
    
    CreatFile(SandPile, parser.save_pictures);
   
    

}
