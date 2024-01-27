using namespace std;
#include <iostream>

void Zadanie1() {
    srand(time(0));
    int numbers[10];
    int positiveNumber=0;
    cout << "Изначальный массив \n";
    for (int i = 0; i < 10 ; i++) {
        numbers[i] = -150 + rand() % 300;
        cout << " " << numbers[i];
    }
    for (int i = 0; i < 10; i++) {
        if (numbers[i] > 0) {
            positiveNumber = numbers[i];
            break;
        }
    }
    if (positiveNumber != 0) {
        cout << "\nПервое положительное число = " << positiveNumber;
        cout << "\nКонечный массив массив \n";

        for (int i = 0; i < 10; i++) {
            if (numbers[i] < 0) {
                numbers[i] = positiveNumber;
            }
            cout << " " << numbers[i];
        }
    }
    else {
        cout << "\nВ массиве нет значений больше 0";
    }
}

void Zadanie2() {
    srand(time(0));
    int numbers[10][10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                numbers[i][j][k] = -150 + rand() % 300;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int summ = 0;
            for (int k = 0; k < 10; k++) {
                summ = numbers[i][j][k];
            }
            cout << "\nСумма плоскости " << i << " " << j << " = " << summ;
        }
    }
}
struct MusicAlbum {
    char title[100];
    char artist[100];
    int year;
};

int albumsCount = 0;
void AddAlbum(MusicAlbum* albums) {
    int year;
    MusicAlbum album{};
    cout << "Введите название альбома\n";
    cin >> album.title;
    cout << "Введите исполнителя\n";
    cin >> album.artist;
    cout << "Введите год выпуска альбома\n";
    cin >> year;
    if (year > 1500 && year <= 2024) {
        album.year = year;
        albums[albumsCount] = album;
        albumsCount += 1;
    }
    else {
        cout << "Неверный год\n";
    }
}

void DeleteAlbum(MusicAlbum* albums) {
    int index;
    if (albumsCount == 0) {
        cout << "У вас пустой список альбомов\n";
        return;
    }
    cout << "Введите индекс альбома\n";
    cin >> index;
    if (index >= albumsCount || index < 0) {
        cout << "Неверный индекс";
        return;
    }
    for (int i = index; i < albumsCount; i++) {
        albums[i] = albums[i + 1];
    }
    albumsCount -= 1;
    cout << "Альбом удален из списка\n";
}
void UpdateAlbum(MusicAlbum* albums) {
    int index;
    int year;
    MusicAlbum album{};
    if (albumsCount == 0) {
        cout << "У вас пустой список альбомов\n";
        return;
    }
    cout << "Введите индекс альбома\n";
    cin >> index;
    if (index >= albumsCount || index < 0) {
        cout << "Неверный индекс";
        return;
    }
    cout << "Введите название альбома\n";
    cin >> album.title;
    cout << "Введите исполнителя\n";
    cin >> album.artist;
    cout << "Введите год выпуска альбома\n";
    cin >> album.year;
    albums[index] = album;
}

void ShowAlbums(MusicAlbum* albums) {
    for (int i = 0; i < albumsCount; i++) {
        cout << "Альбом: " << albums[i].title << ". Исполнитель: " << albums[i].artist << ". Год выпуска: " << albums[i].year << "\n";
    }
}

void Zadanie3() {    

    MusicAlbum albums[100];
    
    while (true) {
        int choise = 0;
        cout << "Выберите действие:\n" << "1 - Добавить альбом\n" << "2 - Удалить альбом\n" << "3 - Обновить данные об альбоме\n" <<"4 - Показать список альбомов\n";
        cin >> choise;
        switch (choise) {
        case 1:
            AddAlbum(albums);
            break;
        case 2:
            DeleteAlbum(albums);
            break;
        case 3:
            UpdateAlbum(albums);
            break;
        case 4:
            ShowAlbums(albums);
            break;
        default:
            cout << "Такого варианта нет\n";
            break;
        }
        cin.clear();
        cin.ignore();
    }
}

class Matrix {
private:
    int matrix[3][3];
    void randomValues() {
        srand(time(0));
        for(int i = 0; i<3;i++)
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = -20 + rand() % 40;
            }
    };
    void showMatrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix[i][j]<< " ";
            }
            cout << "\n";
        }
    }

    
public:
    void CountMatrixDeterminant() {
        randomValues();
        showMatrix();
        int determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) -
            matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) +
            matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
        std::cout << "Определитель матрицы: " << determinant;
    }
};

void Zadanie4() {
    Matrix matrix;
    matrix.CountMatrixDeterminant();
}

int main()
{
    setlocale(LC_ALL, "rus");
    //Zadanie1();
    //Zadanie2();
    //Zadanie3();
    //Zadanie4();
   
}

