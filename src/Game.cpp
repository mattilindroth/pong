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

    if(TTF_Init() == -1) {
        printf("Could not initialize fonts (SDL_ttf.dll)...\n");
        return;
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == NULL) {
        return;
    }
    SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);

    pGameScene = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT);
    pMenuScene = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT);

    pGameScene->SetRenderer(pRenderer);
    pMenuScene->SetRenderer(pRenderer);

    pInputManager = new InputManager();

}

bool Game::AreColliding(GameItem *ball, Paddle *paddle) {
    SDL_Rect *prect = paddle->GetRectangle();
    SDL_Rect *brect = ball->GetRectangle();

    ValueRange *paddlex = new ValueRange(prect->x + prect->w, prect->x);
    ValueRange *paddley = new ValueRange(prect->y + prect->h, prect->y);

    if(paddlex->IsInRange(brect->x) && paddley->IsInRange(brect->y)) {
        return true;
    }
    if(paddlex->IsInRange(brect->x + brect->w) && paddley->IsInRange(brect->y)) {

        return true;
    }
    if(paddlex->IsInRange(brect->x) && paddley->IsInRange(brect->y + brect->h)) {
        return true;
    }
    if(paddlex->IsInRange(brect->x + brect->w) && paddley->IsInRange(brect->y + brect->h)) {
        return true;
    }

    return false;
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

Menu *CreateMenu(SDL_Renderer *renderer) {
    // fprintf(stderr, "In the Game::CreateMenu.\n");
    SDL_Rect menuRectangle;
    menuRectangle.x = 200;
    menuRectangle.y = 100;
    menuRectangle.h = 300;
    menuRectangle.w = 300;
    Menu *menu = new Menu(menuRectangle);
    // fprintf(stderr, "creating begin game menu item.\n");
    MenuItem *beginGame = new MenuItem("Start game", renderer);
    // fprintf(stderr, "creating exit game menu item.\n");
    MenuItem *exitGame = new MenuItem("Exit game", renderer);

    menu->AddMenuItem(beginGame);
    menu->AddMenuItem(exitGame);

//    beginGame->GetRectangle()->y = 10;
//    exitGame->GetRectangle()->y = 30;

    return menu;
}

void Game::Run() {
    SDL_Event e;
    bool quit;

    Paddle *left;
    Paddle *right;
    GameItem *theBall;
    SDL_Surface *surface;
    SDL_Rect *rect1;
    Menu *menu;
    SDL_ShowCursor(SDL_DISABLE);

    bool isEscapeDown = false;
    bool invokeMenu = false;
    int selectedMenu;

    fprintf(stderr, "In the Game::Run method.\n");

    if (pWindow == NULL) {
        printf("SDL window is a null pointer. Exiting...\n");
        return;
    }

    surface = IMG_Load( "white.png" );
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 395; rect1->y = 295;
    rect1->w = 10; rect1->h = 10;
    theBall = new GameItem( surface,  rect1, pGameScene->GetRenderer());

    surface = IMG_Load( "white.png" );
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 0; rect1->y = 0;
    rect1->w = 8; rect1->h = 20;
    left = new Paddle( surface, rect1, pGameScene->GetRenderer()) ;

    surface = IMG_Load( "white.png" );
    if(surface == NULL) {
        fprintf(stderr, "Could not load white.png. Exiting...\n");
        return;
    }
    rect1 = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    rect1->x = 792; rect1->y = 0;
    rect1->w = 8; rect1->h = 20;
    right =  new Paddle(surface, rect1, pGameScene->GetRenderer());

    pGameScene->AddItem(theBall);
    pGameScene->AddItem(left);
    pGameScene->AddItem(right);

    quit = false;

    menu = CreateMenu(pGameScene->GetRenderer());
    theBall->SetSpeed(1, 0);

    while(quit == false) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        /*Check escape key for menu*/
        if(keystates[SDL_SCANCODE_ESCAPE]) {
            isEscapeDown = true;
            invokeMenu  = true;
        } else if(isEscapeDown == true) { //Escape was down but is no more
            // invokeMenu = true;
            isEscapeDown = false;
        }

        if(keystates[SDL_SCANCODE_UP] && !keystates[SDL_SCANCODE_DOWN]) {
            HandlePaddleMove(true, right);
        } else if (!keystates[SDL_SCANCODE_UP] && keystates[SDL_SCANCODE_DOWN]) {
            HandlePaddleMove(false, right);
        } else {
            right->SetSpeed(0, 0);
        }

        if(keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_Z]) {
            HandlePaddleMove(true, left);
        } else if(!keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_Z]) {
            HandlePaddleMove(false, left);
        } else {
            left->SetSpeed(0,0);
        }

        if(AreColliding(theBall, left)) {
            theBall->SetSpeed(-theBall->GetSpeedX(), theBall->GetSpeedY() + left->GetSpeedY());
        }
        if(AreColliding(theBall, right)) {
            theBall->SetSpeed(-theBall->GetSpeedX(), theBall->GetSpeedY()+ right->GetSpeedY());
        }

        rect1 = theBall->GetRectangle();
        if(rect1->y <= 0 || (rect1->y + rect1->h) > SCREEN_HEIGHT) {
            theBall->SetSpeed(theBall->GetSpeedX(), -theBall->GetSpeedY());
        }

        if(rect1->x <= 0 ) {
            //Right player scores
            quit = true;
        } else if((rect1->x + rect1->w) > SCREEN_WIDTH) {
            //Left plater scores
            quit = true;
        }

        theBall->Move(theBall->GetSpeedX(), theBall->GetSpeedY());

        SDL_Delay(10);

        if(invokeMenu) {
            selectedMenu = menu->Show(pMenuScene);
            invokeMenu = false;

            switch(selectedMenu) {
            case -1:
                //Do nothing, continue game
                break;
            case 0:
                //Todo start new game
                break;
            case 1:
                //quit game
                quit = true;
                break;
            }
        }

        while(SDL_PollEvent( &e ) != 0) {
            switch (e.type ) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.scancode) {
                        case SDL_SCANCODE_SPACE:
                            quit = true;
                            break;
                        default:
                            break;
                }
                default:
                    break;
            }
        }

        pGameScene->RenderItems();
    }
}

Game::~Game()
{
    SDL_DestroyRenderer( pRenderer );
    delete pGameScene;
    delete pMenuScene;
    delete pInputManager;
    SDL_DestroyWindow( pWindow );
    IMG_Quit();
    SDL_Quit();
    printf("Game destructor called\n");
}
