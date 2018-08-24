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

bool Game::AreColliding(GameItem *ball, Paddle *paddle) {
    SDL_Rect *prect = paddle->GetRectangle();
    SDL_Rect *brect = ball->GetRectangle();

    ValueRange *paddlex = new ValueRange(prect->x + prect->w, prect->x);
    ValueRange *paddley = new ValueRange(prect->y + prect->h, prect->y);
//    printf("Valuerange paddlex: Min: %i, Max: %i\n", paddlex->GetMin(), paddlex->GetMax());
//    printf("Valuerange paddley: Min: %i, Max: %i\n", paddley->GetMin(), paddley->GetMax());

    if(paddlex->IsInRange(brect->x) && paddley->IsInRange(brect->y)) {
//        printf("first collision if\n");
        return true;
    }
    if(paddlex->IsInRange(brect->x + brect->w) && paddley->IsInRange(brect->y)) {
//        printf("second collision if x: %i y: %i\n", brect->x + brect->w, brect->y);

        return true;
    }
    if(paddlex->IsInRange(brect->x) && paddley->IsInRange(brect->y + brect->h)) {
//        printf("third collision if\n");
        return true;
    }
    if(paddlex->IsInRange(brect->x + brect->w) && paddley->IsInRange(brect->y + brect->h)) {
//        printf("fourth collision if\n");
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

    theBall->SetSpeed(2, 0);

    while(quit == false) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

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
