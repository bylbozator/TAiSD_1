
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

int main()
{
    setlocale(0, "");

    srand(time(0)); // Для инициализации генератора случайных чисел

    int choice;
    int arr1[MAX_SIZE];
    int size1 = 0;
    int arr2[MAX_SIZE][MAX_SIZE];
    int rows2 = 0;
    int cols2 = 0;

    int rows3 = 0;
    int** raggedArray = nullptr;;
    int* sizes = nullptr;;



    do
    {


        cout << "Меню " << endl;
        cout << "1. Выбрать одномерный массив" << endl;
        cout << "2. Выбрать двумерный массив" << endl;
        cout << "3. Выбрать рваный массив" << endl;
        cout << "Любой другой символ. Выход" << endl;
        cout << "Введите номер типа массива: ";
        cin >> choice;

        int fillChoice;
        switch (choice)
        {
        case 1:
            cout << "Выберите способ заполнения одномерного массива:" << endl;
            cout << "1. Вручную" << endl;
            cout << "2. Случайные числа" << endl;
            cout << "Любой другой символ. Выход" << endl;
            cout << "Введите номер способа заполнения: ";


            cin >> fillChoice;

            if (fillChoice == 1) {
                cout << "Введите количество элементов одномерного массива: ";
                cin >> size1;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество элементов заново: ";
                    cin >> size1;
                }

                while (size1 <= 0) {
                    cout << "Количество элементов должно быть больше 0. Введите количество элементов заново: ";
                    cin >> size1;
                }

                cout << "Введите элементы одномерного массива: " << endl;

                for (int i = 0; i < size1; i++) {
                    cin >> arr1[i];
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка. Введите количество элементов заново: ";
                        cin >> arr1[i];
                    }

                }
                cout << endl;
                cout << "Введенный одномерный массив: ";
                for (int i = 0; i < size1; i++) {
                    cout << arr1[i] << " ";
                }
                cout << endl;
            }
            else if (fillChoice == 2) {
                cout << "Введите количество элементов одномерного массива: ";
                cin >> size1;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество элементов заново: ";
                    cin >> size1;
                }
                while (size1 <= 0) {
                    cout << "Количество элементов должно быть больше 0. Введите количество элементов заново: ";
                    cin >> size1;
                }

                cout << "Сгенерированный одномерный массив: ";
                for (int i = 0; i < size1; i++) {
                    int randomNumber = rand() % 100;
                    arr1[i] = randomNumber; // Заполнение массива значениями, сгенерированными случайными числами
                    cout << arr1[i] << " ";
                }
                cout << endl;
            }
            else {
                cout << "Инициализация выхода." << endl;
                return 1;
            }

            // Добавление элемента в конец массива
            int newItem;
            cout << "Введите элемент для добавления в конец массива: ";
            cin >> newItem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка. Введите количество элементов заново: ";
                cin >> newItem;
            }
            if (size1 < MAX_SIZE) {
                arr1[size1] = newItem;
                size1++;
            }
            else {
                cout << "Невозможно добавить элемент, массив полон." << endl;
            }
            cout << "Результат:" << endl;
            for (int i = 0; i < size1; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Выберите способ заполнения двумерного массива:" << endl;
            cout << "1. Вручную" << endl;
            cout << "2. Случайные числа" << endl;
            cout << "Любой другой символ. Выход" << endl;
            cout << "Введите номер способа заполнения: ";
            cin >> fillChoice;

            if (fillChoice == 1) {
                cout << "Введите количество строк двумерного массива: ";
                cin >> rows2;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество строк заново: ";
                    cin >> rows2;
                }
                while (rows2 <= 0) {
                    cout << "Количество строк должно быть больше 0. Введите количество строк заново: ";
                    cin >> rows2;
                }
                cout << "Введите количество столбцов двумерного массива: ";
                cin >> cols2;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество столбцов заново: ";
                    cin >> cols2;
                }
                while (cols2 <= 0) {
                    cout << "Количество столбцов должно быть больше 0. Введите количество столбцов заново: ";
                    cin >> cols2;
                }

                cout << "Введите элементы для двумерного массива:" << endl;
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        cin >> arr2[i][j];

                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Ошибка. Введите количество элементов заново: ";
                            cin >> arr2[i][j];
                        }

                    }
                }
                // Вывод массива
                cout << "Полученный массив:" << endl;
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        cout << arr2[i][j] << " ";
                    }
                    cout << endl;
                }


            }
            else if (fillChoice == 2) {
                cout << "Введите количество строк двумерного массива: ";
                cin >> rows2;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество строк заново: ";
                    cin >> rows2;
                }
                while (rows2 <= 0) {
                    cout << "Количество строк должно быть больше 0. Введите количество строк заново: ";
                    cin >> rows2;
                }

                cout << "Введите количество столбцов двумерного массива: ";
                cin >> cols2;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество столбцов заново: ";
                    cin >> cols2;
                }
                while (cols2 <= 0) {
                    cout << "Количество столбцов должно быть больше 0. Введите количество столбцов заново: ";
                    cin >> cols2;
                }
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        arr2[i][j] = rand() % 100;
                    }
                }
                // Вывод массива
                cout << "Сгенерированный массив:" << endl;
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < cols2; j++) {
                        cout << arr2[i][j] << " ";
                    }
                    cout << endl;
                }

            }

            else {
                cout << "Инициализация выхода." << endl;
                return 1; // Выйти из программы с ошибкой
            }
            // Удаление столбца
            int  numToRemove;

            cout << "Введите номер столбца для удаления";
            cin >> numToRemove;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка. Введите количество строк заново: ";
                cin >> numToRemove;
            }
            while (numToRemove <= 0) {
                cout << "Номер столбца должен быть больше 0. Введите номер столбца заново: ";
                cin >> numToRemove;
            }
            while (numToRemove > cols2) {
                cout << "Номер столбца не существует в данном массиве. Введите номер столбца заново: ";
                cin >> numToRemove;
            }

            for (int i = 0; i < rows2; i++) {
                for (int j = numToRemove - 1; j < cols2 - 1; j++) {
                    arr2[i][j] = arr2[i][j + 1]; // Перемещение элементов влево
                }
            }
            cols2--; // Уменьшение количества столбцов на 1
            // Вывод массива
            cout << "Итоговый массив:" << endl;
            for (int i = 0; i < rows2; i++) {
                for (int j = 0; j < cols2; j++) {
                    cout << arr2[i][j] << " ";
                }
                cout << endl;
            }


            break;
        case 3:

            cout << "Выберите способ заполнения рваного массива:" << endl;
            cout << "1. Вручную" << endl;
            cout << "2. Случайные числа" << endl;
            cout << "Любой другой символ. Выход" << endl;
            cout << "Введите номер способа заполнения: ";
            cin >> fillChoice;

            if (fillChoice == 1) {
                // Заполнение вручную

                cout << "Введите количество строк рваного массива: ";
                cin >> rows3;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество строк заново: ";
                    cin >> rows3;
                }
                while (rows3 <= 0) {
                    cout << "Количество строк должно быть больше 0. Введите количество строк заново: ";
                    cin >> rows3;
                }
                raggedArray = new int* [rows3];
                sizes = new int[rows3];

                for (int i = 0; i < rows3; i++) {
                    cout << "Введите количество элементов в " << i + 1 << " строке: ";
                    int numElements;
                    cin >> numElements;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка. Введите количество строк заново: ";
                        cin >> numElements;
                    }
                    while (numElements <= 0) {
                        cout << "Количество строк должно быть больше 0. Введите количество строк заново: ";
                        cin >> numElements;
                    }
                    sizes[i] = numElements;

                    raggedArray[i] = new int[numElements];


                    cout << "Введите элементы для " << i + 1 << " строки:" << endl;

                    for (int j = 0; j < numElements; j++) {
                        cin >> raggedArray[i][j];
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Ошибка. Введите количество элемнтов заново: ";
                            cin >> raggedArray[i][j];
                        }
                        while (raggedArray[i][j] < 0) {
                            cout << "Количество элементов должно быть больше 0. Введите количество элементов заново: ";
                            cin >> raggedArray[i][j];
                        }
                    }
                }


                cout << "Рваный массив: " << endl;
                for (int i = 0; i < rows3; i++) {
                    for (int j = 0; j < sizes[i]; j++) {
                        cout << raggedArray[i][j] << " ";
                    }
                    cout << endl;

                }






            }
            else if (fillChoice == 2)
            {
                // Заполнение случайными числами

                cout << "Введите количество строк рваного массива: ";
                cin >> rows3;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка. Введите количество строк заново: ";
                    cin >> rows3;
                }
                while (rows3 <= 0) {
                    cout << "Количество строк должно быть больше 0. Введите количество строк заново: ";
                    cin >> rows3;
                }
                raggedArray = new int* [rows3];
                sizes = new int[rows3];

                for (int i = 0; i < rows3; i++) {
                    cout << "Введите количество элементов в " << i + 1 << " строке: ";
                    int numElements;
                    cin >> numElements;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка. Введите количество строк заново: ";
                        cin >> numElements;
                    }
                    sizes[i] = numElements;

                    raggedArray[i] = new int[numElements];

                    for (int j = 0; j < numElements; j++) {
                        int randomNumber = rand() % 100;
                        raggedArray[i][j] = randomNumber;
                    }
                }

                cout << "Сгенерированный рваный массив: " << endl;
                for (int i = 0; i < rows3; i++) {
                    for (int j = 0; j < sizes[i]; j++) {
                        cout << raggedArray[i][j] << " ";
                    }
                    cout << endl;
                }


            }
            else {
                cout << "Инициализация выхода." << endl;
                return 1; // Выйти из программы с ошибкой
            }





            int n;  // Количество строк, которые нужно добавить
            cout << "Введите количество строк для добавления: ";
            cin >> n;

            // Создаем новый массив указателей на целые числа
            int** newRaggedArray = new int* [rows3 + n];

            // Копируем существующие строки из исходного массива в новый массив
            for (int i = 0; i < rows3; i++) {
                newRaggedArray[i] = new int[sizes[i]];
                for (int j = 0; j < sizes[i]; j++) {
                    newRaggedArray[i][j] = raggedArray[i][j];
                }
            }

            // Инициализируем оставшиеся строки нового массива
            for (int i = rows3; i < rows3 + n; i++) {
                size_t numElements;
                cout << "Введите размер " << i + 1 << " строки: ";
                cin >> numElements;

                sizes[i] = numElements;
                newRaggedArray[i] = new int[numElements];

                for (int j = 0; j < numElements; j++) {
                    int randomNumber = rand() % 100;
                    newRaggedArray[i][j] = randomNumber;
                }
            }




            // Присваиваем новый массив переменной raggedArray
            raggedArray = newRaggedArray;

            // Обновляем значение переменной rows3
            rows3 += n;






            // Выводим обновленный массив с добавленными строками
            cout << "Обновленный рваный массив: " << endl;
            for (int i = 0; i < rows3; i++) {
                for (int j = 0; j < sizes[i]; j++) {
                    cout << raggedArray[i][j] << " ";
                }
                cout << endl;
            }





        }


    }

    while (choice != 0);
}
