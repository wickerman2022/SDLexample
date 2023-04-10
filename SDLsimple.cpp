#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

//define some constants
#define WINDOW_TITLE "Simple Test Game"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
//define some colors r, g, b, a
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED 255, 0, 0, 255
#define GREEN 0, 255, 0, 255
#define BLUE 0, 0, 255, 255

class Button {
public:
    Button(int x, int y, int w, int h, const std::string& text) : x(x), y(y), w(w), h(h), text(text) {}

    bool contains(int mx, int my) const {
        return mx >= x && mx < x + w && my >= y && my < y + h;
    }

    void render(SDL_Renderer* renderer, SDL_Color bgColor, SDL_Color fgColor, TTF_Font* font) const {
        SDL_Rect rect = { x, y, w, h };
        SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderFillRect(renderer, &rect);
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fgColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect = { x + (w - surface->w) / 2, y + (h - surface->h) / 2, surface->w, surface->h };
        SDL_RenderCopy(renderer, texture, nullptr, &textRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

private:
    int x, y, w, h;
    std::string text;
};

//Singleton class
class GameEngine {
public:
    static GameEngine& getInstance() {
        static GameEngine instance;
        return instance;
    }

    bool initialize() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
            return false;
        }
        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
        if (window == nullptr) {
            std::cerr << "SDL window creation failed: " << SDL_GetError() << std::endl;
            return false;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            std::cerr << "SDL renderer creation failed: " << SDL_GetError() << std::endl;
            return false;
        }
        return true;
    }

    void run() {
        bool quit = false;
        SDL_Event event;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }

            //Clear screen
			SDL_SetRenderDrawColor(renderer, WHITE);
			SDL_RenderClear(renderer);

			//Render red filled quad
			SDL_Rect fillRect = { 240, 190, 100, 100 };
			SDL_SetRenderDrawColor(renderer, RED);
			SDL_RenderFillRect(renderer, &fillRect);

			//Render green outlined quad
			SDL_Rect outlineRect = { 240, 190, 100, 100 };
			SDL_SetRenderDrawColor(renderer, GREEN);
			SDL_RenderDrawRect(renderer, &outlineRect);
            SDL_RenderPresent(renderer);
        }
    }

    void cleanup() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    GameEngine() {}
    ~GameEngine() {}
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

int main(int argc, char* argv[]) {
    GameEngine& engine = GameEngine::getInstance();
    if (!engine.initialize()) {
        return -1;
    }
    
    Button button(100, 100, 200, 50, "Click Me");
    
    engine.run();
    engine.cleanup();
    return 0;
}

