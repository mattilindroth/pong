#include "Game.h"

Game::Game()
{
    printf("Game constructor called\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize video...\n");
        return;
    }

    pWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED) ;
    if (pWindow == NULL) {
        printf("Could not create window...\n");
        return;
    }

    if (IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG ) < 0 ) {
        printf("Unable to initialize SDL_image library ...\n");
        return;
    }

    pScene = new Scene( pWindow );
}

void Game::HandlePaddleMove(bool Up, Paddle *paddle) {
    if(Up) {
        if(paddle->GetRectangle()->y > 0) {
            paddle->Move(0, -5);
        }
    } else {
        if(paddle->GetRectangle()->y + paddle->GetRectangle()->h < SCREEN_HEIGHT) {
            paddle->Move(0, 5);
        }
    }
}

void Game::Run() {
    SDL_Event e;
    bool quit;
    Paddle *left;
    Paddle *right;
    GameItem *theBall;
    SDL_Surface *surface;
    SDL_Rect *rect1;

    if (pWindow == NULL) {
        printf("SDL window is a null pointer. Exiting...\n");
        return;
    }

    surface = IMG_Load( "white.png" );
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 395; rect1->y = 295;
    rect1->w = 10; rect1->h = 10;
    theBall = new GameItem( surface,  rect1, "The ball" );

    surface = IMG_Load( "white.png" );
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 0; rect1->y = 0;
    rect1->w = 8; rect1->h = 20;
    left = new Paddle( surface, rect1) ; //, "left  paddle");

    surface = IMG_Load( "white.png" );
    if(surface == NULL) {
        fprintf(stderr, "Could not load white.png. Exiting...\n");
        return;
    }
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 792; rect1->y = 0;
    rect1->w = 8; rect1->h = 20;
    right =  new Paddle(surface, rect1); //new GameItem( surface, rect1, "right paddle");

    pScene->AddItem(theBall);
    pScene->AddItem(left);
    pScene->AddItem(right);

    quit = false;

    while(quit == false) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        if(keystates[SDL_SCANCODE_UP] && !keystates[SDL_SCANCODE_DOWN]) {
            HandlePaddleMove(true, right);
        } else if (!keystates[SDL_SCANCODE_UP] && keystates[SDL_SCANCODE_DOWN]) {
            HandlePaddleMove(false, right);
        }
        if(keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_Z]) {
            HandlePaddleMove(true, left);
        } else if(!keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_Z]) {
            HandlePaddleMove(false, left);
        }

        SDL_Delay(20);

        while(SDL_PollEvent( &e ) != 0) {
            switch (e.type ) {
                case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
//                    case SDL_SCANCODE_UP:
//                        //HandleKeyDown();
//                        left->Move(0, -5);
//                        break;
//                    case SDL_SCANCODE_DOWN:
//                        left->Move(0, 5);
//                        break;

                }
            }
        }
        pScene->RenderItems();
    }
}

Game::~Game()
{
    delete pScene;
    SDL_DestroyWindow( pWindow );
    //SDL_DestroyRenderer( pRenderer );
    IMG_Quit();
    SDL_Quit();
    printf("Game destructor called\n");
}
