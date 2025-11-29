#include <iostream>
using namespace std;
#include "CoreLocation-8.h"
#include "Game.h"
#include <chrono>
#include <thread>

void CoreLocation::run()
{
    std::cout << "\n=== ЦЕНТРАЛЬНОЕ ЯДРО ===\n";
    std::cout << "Пространство дрожит. Время искажено.\n";
    std::cout << "Перед тобой три слота панели стабилизации.\n\n";

    bool insertedDisk = false;
    bool insertedCatalyst = false;
    bool insertedChip = false;

    // --- ВСТАВКА ПРЕДМЕТОВ ---
    if (game.hasResearchDisk)
    {
        std::cout << "[1] Вставить жёсткий диск\n";
        std::cout << "Жёсткий диск установлен. Панель принимает данные.\n\n";
        insertedDisk = true;
    }

    if (game.catalystObtained)
    {
        std::cout << "[2] Установить плазменный катализатор\n";
        std::cout << "Катализатор встал в паз. Контур стабилизируется.\n\n";
        insertedCatalyst = true;
    }

    if (game.oxygenChipObtained)
    {
        std::cout << "[3] Вставить микросхему системы жизнеобеспечения\n";
        std::cout << "Микросхема подключена. Фильтры оживают.\n\n";
        insertedChip = true;
    }

    // Если предметов нет вообще
    if (!insertedDisk && !insertedCatalyst && !insertedChip)
    {
        std::cout << "Перед панелью пусто. Нечего вставлять...\n\n";
    }

    // --- РАСЧЁТ КОЛИЧЕСТВА ПРЕДМЕТОВ ---
    int count = 0;
    if (insertedDisk)      count++;
    if (insertedCatalyst)  count++;
    if (insertedChip)      count++;

    std::cout << "Панель анализирует состояние ядра...\n\n";

    // --- ОБРАБОТКА КОНЦОВОК ---
    switch(count)
    {
        case 3:
            idealEnding();
            break;

        case 2:
            twoItemsEnding(insertedDisk, insertedCatalyst, insertedChip);
            break;

        case 1:
            oneItemEnding(insertedDisk, insertedCatalyst, insertedChip);
            break;

        case 0:
            zeroItemsEnding();
            break;
    }

    std::cout << "\n=== КОНЕЦ ИГРЫ ===\n";
    game.stop();
}

// ------------------ КОНЦОВКИ ------------------

void CoreLocation::idealEnding()
{
    std::cout << "Все три компонента установлены.\n";
    std::cout << "Аномалия схлопывается. Станция стабилизирована.\n";
    std::cout << "Ты спас станцию и выжил.\n";
}

void CoreLocation::twoItemsEnding(bool disk, bool catalyst, bool chip)
{
    // 2А — диск + катализатор
    if (disk && catalyst && !chip)
    {
        std::cout << "Данные отправлены, контур стабилен.\n";
        std::cout << "Но система воздуха не работает. Ты задыхаешься.\n";
        return;
    }

    // 2Б — диск + микросхема
    if (disk && chip && !catalyst)
    {
        std::cout << "Данные отправлены, воздух чист.\n";
        std::cout << "Но ядро нестабильно. Время сжимается...\n";
        std::cout << "Ты попал во временную петлю.\n";
        return;
    }

    // 2В — катализатор + микросхема
    if (catalyst && chip && !disk)
    {
        std::cout << "Контур стабилен, воздух чист.\n";
        std::cout << "Но исследования потеряны навсегда.\n";
        std::cout << "Ты выжил, но миссия провалена.\n";
        return;
    }
}

void CoreLocation::oneItemEnding(bool disk, bool catalyst, bool chip)
{
    if (disk)
    {
        std::cout << "Ты отправил данные.\n";
        std::cout << "Но воздух ядовит и ядро нестабильно.\n";
        std::cout << "Ты погиб, но данные спасены.\n";
        return;
    }

    if (catalyst)
    {
        std::cout << "Контур стабилизирован.\n";
        std::cout << "Но ты задохнулся — системы воздуха не работали.\n";
        return;
    }

    if (chip)
    {
        std::cout << "Воздух чист.\n";
        std::cout << "Но без данных и катализатора ядро взрывается.\n";
        std::cout << "Ты проваливаешься в аномалию навечно.\n";
        return;
    }
}

void CoreLocation::zeroItemsEnding()
{
    std::cout << "Ни одного компонента.\n";
    std::cout << "Ядро выходит из-под контроля.\n";
    std::cout << "Ты задыхаешься, а станция разрывается во времени.\n";
}


