// queue cliets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<thread>
#include <atomic>





std::atomic<int> clientsCounter = 0;
int maxClients = 4; // Максимальное количество клиентов
bool flag = true;


void clientThred()
{
    while (flag)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (clientsCounter < maxClients)
        {
            clientsCounter++;
            std::cout << "Клиент пришел. В очереди: " << clientsCounter << std::endl;
        }
        else
        {
            std::cout << "Очередь заполнена. Новые клиенты не принимаются." << std::endl;
            flag = false;
        }
    }
}

    void operatorThread()
    {
            while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
                if (clientsCounter > 0)
                {
                clientsCounter--;
                std::cout << "Операционист обслуживает клиента. В очереди: " << clientsCounter << std::endl;
                }
            else
                {
                std::cout << "Очередь пуста. Операционист завершил работу." << std::endl;
                break;
                }
         }
    }

    int main()
    {
       
        setlocale(LC_ALL, "Russian");


         std::thread th1(clientThred);
         std::thread th2(operatorThread);
          th1.join();
          th2.join();
          return 0;

    }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
