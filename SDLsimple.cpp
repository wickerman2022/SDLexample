#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <memory>

//define some constants
#define WINDOW_TITLE "Simple Test Game"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define STARTING_MONEY 1000
#define MAX_MONEY 1000000
//define some colors r, g, b, a
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED 255, 0, 0, 255
#define GREEN 0, 255, 0, 255
#define BLUE 0, 0, 255, 255

class GameObject
{
public:
    virtual void Update(double dt) = 0;
    virtual ~GameObject() {}
};

class Player: public GameObject
{
public:
    Player(){ money = STARTING_MONEY; score = 0;};

    //Other methods
    virtual void Update(double dt) {};
    virtual void Render() {};
    void EarnMoney(int amount) { money += amount; if (money >= MAX_MONEY) money = MAX_MONEY;};
    void SpendMoney(int amount) {if (money >= amount) money -= amount;};
private:
    int money; // Amount of money
    int score; // Score
};

class InterfaceObject{
public:
    virtual void render(SDL_Renderer* renderer, SDL_Color bgColor, SDL_Color fgColor, TTF_Font* font) const = 0;
    virtual void update() = 0;
    virtual ~InterfaceObject() {}
};

class Button  : public InterfaceObject{
public:
    Button(int x, int y, int w, int h, const std::string& text) : x(x), y(y), w(w), h(h), text(text) {}

    bool contains(int mx, int my) const {
        return mx >= x && mx < x + w && my >= y && my < y + h;
    }

    void update() override {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        if (contains(mx, my)) {
            std::cout << "Mouse is over button" << std::endl;
        }
    }
    
    void render(SDL_Renderer* renderer, SDL_Color bgColor, SDL_Color fgColor, TTF_Font* font) const {
        SDL_Rect rect = { x, y, w, h };
        SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderFillRect(renderer, &rect);

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fgColor);
        if (surface == nullptr) {
            std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
        }

        SDL_Rect textRect = { x + (w - surface->w) / 2, y + (h - surface->h) / 2, surface->w, surface->h };
        SDL_RenderCopy(renderer, texture, nullptr, &textRect);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

private:
    int x, y, w, h;
    std::string text;
};

class Menu : public InterfaceObject {
public:
    void addButton(std::shared_ptr<Button> button) {
        buttons.push_back(button);
    }

    void render(SDL_Renderer* renderer, SDL_Color bgColor, SDL_Color fgColor, TTF_Font* font) const override {
        for (const auto& button : buttons) {
            button->render(renderer, bgColor, fgColor, font);
        }
    }

    void update() override {
        for (const auto& button : buttons) {
            button->update();
        }
    }

private:
    std::vector<std::shared_ptr<Button>> buttons;
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
        if (TTF_Init() != 0) {
            std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
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
        font = TTF_OpenFont("/usr/share/fonts/truetype/ubuntu/UbuntuMono-R.ttf", 24);
        if (font == nullptr) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return false;
        }
        return true;
    }

    void run() {
        bool quit = false;
        //render all InterfaceObjects
            SDL_SetRenderDrawColor(renderer, WHITE);
            SDL_RenderClear(renderer);

            for (const auto& object : interfaceObjects) {
                object->render(renderer, {GREEN}, {BLACK}, font);
            }

            SDL_RenderPresent(renderer);
        SDL_Event event;
        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }
			for (const auto& object : interfaceObjects) {
                object->update();
            }

        }
    }
    
    //add an InterfaceObject to the list of objects to render
    void addInterfaceObject(std::shared_ptr<InterfaceObject> object) {
        interfaceObjects.push_back(object);
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
    TTF_Font* font = nullptr;
    std::vector<std::shared_ptr<InterfaceObject>> interfaceObjects;
};

int main(int argc, char* argv[]) {
    GameEngine& engine = GameEngine::getInstance();
    if (!engine.initialize()) {
        return -1;
    }
    
    auto button1 = std::make_shared<Button>(100, 100, 200, 50, "Button 1");
    auto button2 = std::make_shared<Button>(100, 200, 200, 50, "Button 2");
    
    auto menu = std::make_shared<Menu>();
    menu->addButton(button1);
    menu->addButton(button2);
    
    engine.addInterfaceObject(menu);
    
    std::unique_ptr<Player> player(new Player());
    
    engine.run();
    engine.cleanup();
    return 0;
}
