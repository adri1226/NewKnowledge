#include "PlayTurnViewBase.hpp"

PlayTurnViewBase::PlayTurnViewBase(): View(){}

PlayTurnViewBase::PlayTurnViewBase(std::shared_ptr<Language> language): View(language){}

void PlayTurnViewBase::showWinner(const char * playerName)
{
    printf(_language->getMessage(Language::Message::PlayerWinner), playerName);
}

void PlayTurnViewBase::showBoard(const Board board)
{
    printf(board.toString().c_str());
}

void PlayTurnViewBase::showGameDraw()
{
    printf(_language->getMessage(Language::Message::GameDraw));
}

void PlayTurnViewBase::showProgressBar()
{
    float progress = 0.0;
    int numDots = 0;
    bool increasing = true;

    while (progress < 6)
    {

        printf(_language->getMessage(Language::Message::Loading));

        size_t textSize = strlen(_language->getMessage(Language::Message::Loading));
        size_t spaces = textSize + numDots;

        for (int i{0}; i < numDots; ++i)
        {
            printf(".");
        }

        printf("\r");
        fflush(stdout);

        if (increasing)
        {
            numDots++;
            if (numDots == 3)
            {
                increasing = false;
            }
        } else
        {
            numDots--;
            if (numDots == 0) {
                increasing = true;
            }
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        for(size_t numSpaces{0}; numSpaces < spaces; numSpaces++)
        {
            printf(" ");
        }
        printf("\r");
        fflush(stdout);

        progress++;
    }
}

void PlayTurnViewBase::cleanScreen()
{
    printf("\033[2J\033[H");
}
