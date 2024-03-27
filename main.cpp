#include <iostream>
#include <string>
#include "Race_simulator_lib/Vehicles.h"

#include "Race_simulator_lib/Land_vehicles.h"
#include "Race_simulator_lib/Camel.h"
#include "Race_simulator_lib/Fast_camel.h"
#include "Race_simulator_lib/Centaur.h"
#include "Race_simulator_lib/All_terrain_boots.h"

#include "Race_simulator_lib/Air_vehicles.h"
#include "Race_simulator_lib/Magic_carpet.h"
#include "Race_simulator_lib/Eagle.h"
#include "Race_simulator_lib/Broom.h"

void quick_sort(Vehicles *arr, int size) {

    int left = 0;
    int right = size - 1;

    Vehicles mid = arr[size / 2];
    do {
        while (arr[left].Time() < mid.Time()) {
            left++;
        }
        while (arr[right].Time() > mid.Time()) {
            right--;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    } while (left <= right);
    if (right > 0) {
        quick_sort(arr, right + 1);
    }
    if (left < size) {
        quick_sort(&arr[left], size - left);
    }
}

bool Check(Vehicles *arr, int count, Vehicles name) {
    for (int i = 0; i < count; i++) {
        if (arr[i].GetName() == name.GetName()) {
            return false;
        }
    }
    return true;
}

void PrintList(Vehicles *arr, int count) {
    int a = 1;
    for (int i = 0; i < count; ++i) {
        std::cout << a << " " << arr[i].GetName() << " Время: " << arr[i].Time() << std::endl;
        ++a;
    }
}

int GameMod(int t) {
    if (t == 1) {
        return 1;
    } else if (t == 2) {
        return 2;
    } else if (t == 3) {
        return 3;
    }
    return 0;
}

void ErrorFun(int num) {
    if (num == 0) {
        std::cout << " Не верно! " << std::endl;
        std::cout << std::endl;
    } else if (num == 1) {
        std::cout << " Не верный тип гонки! " << std::endl;
        std::cout << std::endl;
    } else if (num == 2) {
        std::cout << " Не верный тип транспорта! " << std::endl;
        std::cout << std::endl;
    } else if (num == 3) {
        std::cout << " Должно быть зарегистрированно хотя бы 2 транспортных средства! " << std::endl;
        std::cout << std::endl;
    }
}

void NameDuplication(Vehicles &name) {
    std::cout << name.GetName() << " уже зарегистрирован!" << std::endl;
}

void transportList() {
    std::cout << "1. Верблюд " << std::endl;
    std::cout << "2. Верблюд-быстроход " << std::endl;
    std::cout << "3. Кентавр " << std::endl;
    std::cout << "4. Ботинки-вездеходы " << std::endl;
    std::cout << "5. Ковер-самолет " << std::endl;
    std::cout << "6. Орел " << std::endl;
    std::cout << "7. Метла " << std::endl;
    std::cout << "0. Закончить регистрацию " << std::endl;
}

void RaceType(int i, int tmp_i, int count, int distance, int race_type, Vehicles *arr) {
    if (i > tmp_i && i != tmp_i) {

        std::cout << arr[i - 1].GetName() << " успешно зарегистрирован! "
                  << std::endl;
    }
    if (race_type == 1) {
        std::cout << "Гонка для наземного транспорта!Расстояние: " << distance << std::endl;
    } else if (race_type == 2) {
        std::cout << "Гонка для воздушного транспорта! Расстояние: " << distance
                  << std::endl;
    } else if (race_type == 3) {
        std::cout << "Гонка для наземного и воздушного транспорта! Расстояние: " << distance
                  << std::endl;
    }

    if (count >= 1) {
        std::cout << "Зарегистрированные транспортные средства: ";

        for (int i = 0; i < count; i++) {
            if (i >= 1) { std::cout << ", "; }
            std::cout << arr[i].GetName();

        }
        std::cout << std::endl;
    }

}

int main() {

    bool restart = true;
    while (restart == true) {
        system("clear"); // для win везде заменить clear на cls
        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;


        int race_type = 0;

        while (race_type <= 0 || race_type > 3) {
            std::cout << "Выберите тип гонки: ";
            std::cin >> race_type;
            if (race_type > 0 && race_type <= 3) {
                GameMod(race_type);
            } else {
                ErrorFun(1);
            }
        }

        std::cout << std::endl;
        system("clear");

        int distance = 0;
        while (distance <= 0) {
            std::cout << "Укажите длину дистанции (дистанция должна быть положительна): ";
            std::cin >> distance;
        }
        system("clear");

        Camel camel(distance);

        Fast_camel speed_camel(distance);

        Centaur centaur(distance);

        All_terrain_boots all_terrain_boots(distance);

        Magic_carpet magic_carpet(distance);

        Eagle eagle(distance);

        Broom broom(distance);

        std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства" << std::endl;

        unsigned int size = 7;
        int count = 0;

        Vehicles *arr = new Vehicles[size]();

        int i = 0;
        int tmp_i = 0;
        int reg_start = 0;
        bool start_game = false;

        do {
            int end = 1;

            if (count <= 0) {
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
            } else {
                std::cout << "1. Зарегистрировать транспорт" << std::endl;
                std::cout << "2. Начать гонку" << std::endl;
            }

            std::cout << "Выберите действие: ";
            std::cin >> reg_start;

            system("clear");
            if (reg_start != 1 && count <= 0) {
                std::cout << "Введите 1!" << std::endl;
            } else if (reg_start != 1 && reg_start != 2) {
                std::cout << "Введите 1 или 2!" << std::endl;
            } else if (reg_start == 1) {
                do {

                    if (race_type == 1) {
                        RaceType(i, tmp_i, count, distance, race_type, arr);
                    }
                    if (race_type == 2) {
                        RaceType(i, tmp_i, count, distance, race_type, arr);
                    }
                    if (race_type == 3) {
                        RaceType(i, tmp_i, count, distance, race_type, arr);
                    }

                    transportList();

                    int num;
                    std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
                    std::cin >> num;
                    std::cout << std::endl;
                    system("clear");
                    if (num < 0 || num > 7) {
                        ErrorFun(0);
                    } else {
                        switch (num) {
                            case 1:
                                if (Check(arr, count, camel) == true) {
                                    if (camel.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3) {
                                        arr[i] = camel;
                                        tmp_i = i;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }

                                } else {
                                    NameDuplication(camel);
                                    tmp_i = i;
                                }
                                break;
                            case 2:
                                if (Check(arr, count, speed_camel) == true) {
                                    if (speed_camel.TypeOfTransport() == GameMod(race_type) ||
                                        GameMod(race_type) == 3) {
                                        arr[i] = speed_camel;
                                        tmp_i = i;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(speed_camel);
                                    tmp_i = i;
                                }

                                break;
                            case 3:
                                if (Check(arr, count, centaur) == true) {
                                    if (centaur.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3) {
                                        arr[i] = centaur;
                                        tmp_i = i;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(centaur);
                                    tmp_i = i;
                                }

                                break;
                            case 4:
                                if (Check(arr, count, all_terrain_boots) == true) {
                                    if (all_terrain_boots.TypeOfTransport() == GameMod(race_type) ||
                                        GameMod(race_type) == 3) {
                                        arr[i] = all_terrain_boots;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(all_terrain_boots);
                                    tmp_i = i;
                                }

                                break;
                            case 5:
                                if (Check(arr, count, magic_carpet) == true) {
                                    if (magic_carpet.TypeOfTransport() == GameMod(race_type) ||
                                        GameMod(race_type) == 3) {
                                        arr[i] = magic_carpet;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(magic_carpet);
                                    tmp_i = i;
                                }

                                break;
                            case 6:
                                if (Check(arr, count, eagle) == true) {
                                    if (eagle.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3) {
                                        arr[i] = eagle;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(eagle);
                                    tmp_i = i;
                                }

                                break;
                            case 7:
                                if (Check(arr, count, broom) == true) {
                                    if (broom.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3) {
                                        arr[i] = broom;
                                        ++i;
                                        ++count;
                                    } else {
                                        ErrorFun(2);
                                        tmp_i = i;
                                    }
                                } else {
                                    NameDuplication(broom);
                                    tmp_i = i;
                                }

                                break;
                            case 0:
                                if (count >= 2) {
                                    end = 0;
                                } else {
                                    ErrorFun(3);
                                }
                                break;
                        }
                    }

                } while (end != 0);
            } else if (reg_start == 2 && count >= 2) {
                start_game = true;
            }
        } while (start_game == false);

        quick_sort(arr, count);

        PrintList(arr, count);

        delete[] arr;

        int res = 0;
        do {
            std::cout << "1. Провести еще одну гонку" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> res;
            if (res < 1 && res > 2) {
                ErrorFun(0);
            } else if (res == 1) {
                restart = true;
            } else if (res == 2) {
                restart = false;
            }
        } while (res != 1 && res != 2);

        system("clear");
    }

    return 0;
}