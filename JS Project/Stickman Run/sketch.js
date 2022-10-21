/*

- Copy your game project code into this file
- for the p5.Sound library look here https://p5js.org/reference/#/libraries/p5.sound
- for finding cool sounds perhaps look here
https://freesound.org/


*/

var gameChar_x;
var gameChar_y;
var floorPos_y;
var scrollPos;
var gameChar_world_x;

var isLeft;
var isRight;
var isFalling;
var isPlummeting;



var canyons;
var collectable;
var trees;
var clouds;
var mountains;


var lives;
var game_score;
var flagpole;
var platforms;
var enemies;


var jumpSound;
var scoreCollectedSound;
var liveLoseSound;
var gameStartSound;
var levelCompleteSound;
var gameOverSound;
var walkingSound;

function preload()
{
    soundFormats('mp3','wav');
    
    //load your sounds here
    jumpSound = loadSound('assets/jump.wav');
    jumpSound.setVolume(1);
    scoreCollectedSound = loadSound('assets/score.wav');
    scoreCollectedSound.setVolume(1);
    gameStartSound = loadSound('assets/bgm.mp3');
    gameStartSound.setVolume(0.05);
    liveLoseSound = loadSound('assets/loselife.wav');
    liveLoseSound.setVolume(1);
    gameOverSound = loadSound('assets/gameover.wav');
    gameOverSound.setVolume(0.5);
    levelCompleteSound = loadSound('assets/win.wav');
    levelCompleteSound.setVolume(0.1);
    walkingSound = loadSound('assets/walking.wav');
    walkingSound.setVolume(0.2);
    walkingSound.rate(2);
}


function setup()
{
	createCanvas(1024, 576);
    lives = 4;
    startGame();
    gameStartSound.play();
    window.confirm("press WASD to move and jump, collect the keys and find the flag to win")
}
    function startGame()
{
    floorPos_y = height * 3/4;
    gameChar_x = 45;
	gameChar_y = floorPos_y;
    game_score = 0;
	// Variable to control the background scrolling.
	scrollPos = 0;

	// Variable to store the real position of the gameChar in the game
	// world. Needed for collision detection.
	gameChar_world_x = gameChar_x - scrollPos;

	// Boolean variables to control the movement of the game character.
	isLeft = false;
	isRight = false;
	isFalling = false;
	isPlummeting = false;

	// Initialise arrays of scenery objects.
    trees_x =[75,300,600,900,1100,1300,1575,1800,1875,2100,2400,2700,2800,2900,3100,3375,3600,3800,3900];
    
    clouds = 
    [
        {pos_x: 200, pos_y: 120},
        {pos_x: 220, pos_y: 120},
        {pos_x : 400, pos_y: 150},
        {pos_x : 420, pos_y: 150},
        {pos_x : 700, pos_y: 100},
        {pos_x : 720, pos_y: 100},
        {pos_x : 1300, pos_y: 100},
        {pos_x : 1300, pos_y: 100},
        {pos_x : 1600, pos_y: 100},
        {pos_x : 1550, pos_y: 80},
        {pos_x : 1650, pos_y: 100},
        {pos_x : 2000, pos_y: 100},
        {pos_x : 2020, pos_y: 100},
        {pos_x : 2200, pos_y: 100},
        {pos_x : 2220, pos_y: 100},
        {pos_x : 2500, pos_y: 100},
        {pos_x : 2520, pos_y: 100},
        {pos_x : 3100, pos_y: 100},
        {pos_x : 3100, pos_y: 100},
        {pos_x : 3400, pos_y: 100},
        {pos_x : 3500, pos_y: 100},
        {pos_x : 3600, pos_y: 100},
        {pos_x : 3700, pos_y: 100},
    ];
    
    mountains = 
    [
        {pos_x: 450, pos_y: 400},
        {pos_x: 600, pos_y: 400},
        {pos_x: 700, pos_y: 400},
        {pos_x: 1400, pos_y: 400},
        {pos_x: 1550, pos_y: 400},
        {pos_x: 1650, pos_y: 400},
        {pos_x: 2300, pos_y: 400},
        {pos_x: 2800, pos_y: 400},
        {pos_x: 3300, pos_y: 400},
        
    ];
    
    canyons = 
    [
        {x_pos: 100, width: 135},
        {x_pos: 400, width: 135},
        {x_pos: 700, width: 135},
        {x_pos: 940, width: 135},
        {x_pos: 1400, width: 135},
        {x_pos: 1600, width: 135},
        {x_pos: 1950, width: 135},
        {x_pos: 2200, width: 135},
        {x_pos: 2500, width: 135},
        {x_pos: 2925, width: 135},
        {x_pos: 3150, width: 135},
        
    ];
    
    collectable = 
    [
        {x_pos: 220, y_pos: 350, size: 50, isFound: false},
        {x_pos: 280, y_pos: 420, size: 50, isFound: false},
        {x_pos: 350, y_pos: 420, size: 50, isFound: false},
        {x_pos: 475, y_pos: 330, size: 50, isFound: false},
        {x_pos: 550, y_pos: 250, size: 50, isFound: false},
        {x_pos: 580, y_pos: 420, size: 50, isFound: false},
        {x_pos: 650, y_pos: 420, size: 50, isFound: false},
        {x_pos: 750, y_pos: 350, size: 50, isFound: false},
        {x_pos: 880, y_pos: 420, size: 50, isFound: false},
        {x_pos: 1000, y_pos: 350, size: 50, isFound: false},
        {x_pos: 1150, y_pos: 420, size: 50, isFound: false},
        {x_pos: 1250, y_pos: 420, size: 50, isFound: false},
        {x_pos: 1350, y_pos: 420, size: 50, isFound: false},
        {x_pos: 1470, y_pos: 330, size: 50, isFound: false},
        {x_pos: 1570, y_pos: 230, size: 50, isFound: false},
        {x_pos: 1770, y_pos: 180, size: 50, isFound: false},
        {x_pos: 1800, y_pos: 420, size: 50, isFound: false},
        {x_pos: 1900, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2000, y_pos: 350, size: 50, isFound: false},
        {x_pos: 2140, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2260, y_pos: 350, size: 50, isFound: false},
        {x_pos: 2375, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2450, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2570, y_pos: 330, size: 50, isFound: false},
        {x_pos: 2750, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2850, y_pos: 420, size: 50, isFound: false},
        {x_pos: 2985, y_pos: 350, size: 50, isFound: false},
        {x_pos: 3095, y_pos: 420, size: 50, isFound: false},
        {x_pos: 3350, y_pos: 420, size: 50, isFound: false},
        {x_pos: 3550, y_pos: 420, size: 50, isFound: false},
        {x_pos: 3750, y_pos: 420, size: 50, isFound: false},
    ];

        flagpole = {x_pos: 4000, isReached: false, height: 200};
        platforms = [];
    
        platforms.push(createPlatform(435, 350, 80));
        platforms.push(createPlatform(1200, 325, 100));
        platforms.push(createPlatform(1430, 350, 80));
        platforms.push(createPlatform(1540, 250, 60));
        platforms.push(createPlatform(2110, 325, 60));
        platforms.push(createPlatform(2540, 350, 60));
        platforms.push(createPlatform(3075, 350, 60));
        platforms.push(createPlatform(3310, 350, 80));
        platforms.push(createPlatform(3510, 350, 80));
        platforms.push(createPlatform(3710, 350, 80));
    
//    platforms.push(createPlatform(450, 275, 100));
//    
//    platforms.push(createPlatform(570, 200, 100));
        enemies = [];
        enemies.push(new Enemy(550, floorPos_y, 120));
        enemies.push(new Enemy(1100, floorPos_y, 250));
        enemies.push(new Enemy(1535, floorPos_y, 45));
        enemies.push(new Enemy(2085, floorPos_y, 100));
        enemies.push(new Enemy(3060, floorPos_y, 75));
        enemies.push(new Enemy(3300, floorPos_y, 100));
        enemies.push(new Enemy(3500, floorPos_y, 100));
        enemies.push(new Enemy(3700, floorPos_y, 100));
}


function draw()
{
	background(100, 155, 255); // fill the sky blue

	noStroke();
	fill(0,155,0);
	rect(0, floorPos_y, width, height/4); // draw some green ground

	push();
    translate(scrollPos, 0);
    
    // Draw clouds.

    drawClouds();
    
	// Draw mountains.
    
    drawMountains();
	
    // Draw trees.
    
    drawTrees();
    
	// Draw canyons.
   
    for(var i = 0; i < canyons.length; i++)
    {
        drawCanyon(canyons[i]);
        checkCanyon(canyons[i]);
    }
	// Draw collectable items.
    for(var i = 0; i < collectable.length; i++)
    {
        if(collectable[i].isFound == false)
        {
        drawCollectable(collectable[i]);
        checkCollectable(collectable[i]);
        }
    }
    
        if(!checkFlagpole.isReached)
        {
            checkFlagpole(flagpole);
        }
    
    drawFlagpole(flagpole);
    for(var i = 0; i < platforms.length; i++)
    {
        platforms[i].draw();
    }
    for(var i = 0; i < enemies.length; i++)
    {
        enemies[i].update();
        enemies[i].draw();
        if(enemies[i].isContact(gameChar_world_x, gameChar_y))
        {
            liveLoseSound.play();
            startGame();
            lives -= 1;
            break;
        }
    }        
    
    pop();
	
    // Draw game character.

	drawGameChar();
    
    text("lives:" + lives, 20, 60)
    
    if(lives <= 0)
    {
//        gameOverSound.loop();
        text("game over - press space to continue", width/4.5, height/2);
        return;
        
    }
    else if(flagpole.isReached)
    {
        
        text("level complete - press space to continue", width/4.5, height/2)
        return; 
    }
    
    if(gameChar_y > 600)
    {
        if(lives > 0)
        lives -= 1;
        liveLoseSound.play();
        startGame();
    }
	
    // Logic to make the game character move or the background scroll.
	if(isLeft)
	{
		if(gameChar_x > width * 0.2)
		{
			gameChar_x -= 5;
		}
		else
		{
			scrollPos += 5;
		}
	}

	if(isRight)
	{
		if(gameChar_x < width * 0.8)
		{
			gameChar_x  += 5;
		}
		else
		{
			scrollPos -= 5; // negative for moving against the background
		}
	}

	// Logic to make the game character rise and fall.
    if(gameChar_y < floorPos_y - 2)
    {
        var isContact = false; 
        
        for(var i = 0; i < platforms.length; i++)
        {
            if(
                platforms[i].checkContact(gameChar_world_x, gameChar_y) == true
            )
            {
                isContact = true;
                break;
            }
        }
        
        if(isContact == false)
        {
            gameChar_y += 2.5;
            isFalling =true;
        }
        else
        {
            isFalling = false;
        }
    }
    else
    {
        isFalling = false;
    }
    
     
    if(isPlummeting == true)
    {
        gameChar_y += 10;
    }
	// Update real position of gameChar for collision detection.
	gameChar_world_x = gameChar_x - scrollPos;
    gameScoreBoard();
    liveCount();

}

// ---------------------
// Key control functions
// ---------------------

function keyPressed()
{
    if(flagpole.isReached && key == ' ')
    {
        lives = 4;
        startGame();
    }
    else if(lives == 0 && key == ' ')
    {
        lives = 4;
//        gameOverSound.play();
        startGame();
        gameOverSound.play();
    }
    console.log("press" + keyCode);
	console.log("press" + key);
    
    if(keyCode == 65 || key == 'A')//key A
        {
            isLeft = true;
            walkingSound.loop();
        }
    
    
    if(keyCode == 68 || key == 'D')//key D
        {
            isRight = true;
            walkingSound.loop();
        }
   
    if(keyCode == 87 || key == 'W')//key W 
       {
           if(!isFalling)
            {
                gameChar_y -= 150;
                jumpSound.play();
                walkingSound.stop();
            }
       }
}

function keyReleased(){
    if (keyCode ==65)
    {
        isLeft = false;
        walkingSound.stop();
    }
    else if (keyCode ==68)
    {
        isRight = false;
        walkingSound.stop();
    }
    else if (keyCode ==87)
    {
        isFalling = false;
    }
    else{}
    }

// ------------------------------
// Game character render function
// ------------------------------

// Function to draw the game character.

function drawGameChar()
{
		
	if(isLeft && isFalling)
	{
        // add your jumping-left code
        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x-12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x+4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x-10,gameChar_y-59,5,2);
        ellipse(gameChar_x+10,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-47);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+15,gameChar_y-27);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x-7,gameChar_y-15);
        line(gameChar_x-7,gameChar_y-15,gameChar_x-13,gameChar_y-5);
        line(gameChar_x,gameChar_y-20,gameChar_x+5,gameChar_y-10);
        line(gameChar_x+5,gameChar_y-10,gameChar_x+15,gameChar_y-18);
	}
	else if(isRight && isFalling)
	{
		// add your jumping-right code

        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x+12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x-4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x+12,gameChar_y-59,5,2);
        ellipse(gameChar_x-8,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-27);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+15,gameChar_y-47);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x+7,gameChar_y-15);
        line(gameChar_x+7,gameChar_y-15,gameChar_x+13,gameChar_y-5);
        line(gameChar_x,gameChar_y-20,gameChar_x-5,gameChar_y-10);
        line(gameChar_x-5,gameChar_y-10,gameChar_x-15,gameChar_y-18);
    }
	else if(isLeft)
	{
		// add your walking left code
        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x-12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x+4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x-10,gameChar_y-59,5,2);
        ellipse(gameChar_x+10,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-47);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+15,gameChar_y-27);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x-10,gameChar_y-10);
        line(gameChar_x-10,gameChar_y-10,gameChar_x-10,gameChar_y-2);
        line(gameChar_x,gameChar_y-20,gameChar_x+5,gameChar_y-10);
        line(gameChar_x+5,gameChar_y-10,gameChar_x+15,gameChar_y-2);

	}
	else if(isRight)
	{
		// add your walking right code
        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x+12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x-4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x+12,gameChar_y-59,5,2);
        ellipse(gameChar_x-8,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-27);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+15,gameChar_y-47);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x+10,gameChar_y-10);
        line(gameChar_x+10,gameChar_y-10,gameChar_x+10,gameChar_y-2);
        line(gameChar_x,gameChar_y-20,gameChar_x-5,gameChar_y-10);
        line(gameChar_x-5,gameChar_y-10,gameChar_x-15,gameChar_y-2);
	}
	else if(isFalling || isPlummeting)
	{
		// add your jumping facing forwards code
        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x-12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x+4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x-10,gameChar_y-59,5,2);
        ellipse(gameChar_x+10,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-47);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+15,gameChar_y-47);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x-18,gameChar_y-9);
        line(gameChar_x,gameChar_y-20,gameChar_x+18,gameChar_y-9);
        //atmosphere
        line(gameChar_x+5,gameChar_y-9,gameChar_x+5,gameChar_y-2);
        line(gameChar_x+10,gameChar_y-9,gameChar_x+10,gameChar_y-2);
        line(gameChar_x,gameChar_y-9,gameChar_x,gameChar_y-2);
        line(gameChar_x-5,gameChar_y-9,gameChar_x-5,gameChar_y-2);
        line(gameChar_x-10,gameChar_y-9,gameChar_x-10,gameChar_y-2);
	}
	else
	{
		// add your standing front facing code
        //head
        fill(244,164,96);
        stroke(0);
        strokeWeight(0.25);
        ellipse(gameChar_x,gameChar_y-57,30,30);
        strokeWeight(0);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-57,28,28);
        //eyes
        fill(255);
        stroke(244,164,96);
        strokeWeight(0.25);
        ellipse(gameChar_x-8,gameChar_y-62,13,3);
        ellipse(gameChar_x+8,gameChar_y-62,13,3);
        strokeWeight(0)
        fill(139,69,19);
        ellipse(gameChar_x-12,gameChar_y-62,2.5,2.5);
        ellipse(gameChar_x+4,gameChar_y-62,2.5,2.5);
        //mouth
        fill(139,69,19);
        ellipse(gameChar_x,gameChar_y-54,20,14);
        fill(255,228,181);
        ellipse(gameChar_x,gameChar_y-54,20,10);
        ellipse(gameChar_x,gameChar_y-56,21,10.2);
        ellipse(gameChar_x,gameChar_y-52.3,17,8);
        //rouge
        fill(240,128,128);
        ellipse(gameChar_x-10,gameChar_y-59,5,2);
        ellipse(gameChar_x+10,gameChar_y-59,5,2);
        //eyebrow
        fill(0);
        triangle(gameChar_x-8,gameChar_y-65,gameChar_x-4,gameChar_y-67,gameChar_x-10,gameChar_y-65);
        triangle(gameChar_x+8,gameChar_y-65,gameChar_x+4,gameChar_y-67,gameChar_x+10,gameChar_y-65);
        //body
        stroke(0);
        strokeWeight(1.5);
        line(gameChar_x,gameChar_y-41,gameChar_x,gameChar_y-20);
        //lefthand
        line(gameChar_x,gameChar_y-37,gameChar_x-15,gameChar_y-37);
        line(gameChar_x-15,gameChar_y-37,gameChar_x-15,gameChar_y-27);
        //righthand
        line(gameChar_x,gameChar_y-37,gameChar_x+15,gameChar_y-37);
        line(gameChar_x+15,gameChar_y-37,gameChar_x+5,gameChar_y-27);
        //legs
        line(gameChar_x,gameChar_y-20,gameChar_x-15,gameChar_y-2);
        line(gameChar_x,gameChar_y-20,gameChar_x+15,gameChar_y-2);
    }
}

// ---------------------------
// Background render functions
// ---------------------------

// Function to draw cloud objects.
function drawClouds()
{
    for(var a = 0; a < clouds.length; a++)
    {
        noStroke();
        fill(255,255,255);
        ellipse(clouds[a].pos_x,clouds[a].pos_y-60,40-5,40-5);
        ellipse(clouds[a].pos_x+20,clouds[a].pos_y-60,40-5,40-5);
        ellipse(clouds[a].pos_x-13,clouds[a].pos_y-50,40-5,40-5);
        ellipse(clouds[a].pos_x+33,clouds[a].pos_y-50,40-5,40-5);
        ellipse(clouds[a].pos_x+10,clouds[a].pos_y-50,40-5,40-5);
    }
}
// Function to draw mountains objects.
function drawMountains()
{
    for(var b = 0; b < mountains.length; b ++)
    {
        fill(0,139,139);
        triangle(mountains[b].pos_x,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+150,
                 mountains[b].pos_y-144,
                 mountains[b].pos_x+200,
                 mountains[b].pos_y+32);
        triangle(mountains[b].pos_x+624,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+474,
                 mountains[b].pos_y-144,
                 mountains[b].pos_x+424,
                 mountains[b].pos_y+32);
        triangle(mountains[b].pos_x+200,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+424,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+312,
                 mountains[b].pos_y-300);       
        triangle(mountains[b].pos_x+12,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+200,
                 mountains[b].pos_y-100,
                 mountains[b].pos_x+325,
                 mountains[b].pos_y+32);
        triangle(mountains[b].pos_x+624,
                 mountains[b].pos_y+32,
                 mountains[b].pos_x+430,
                 mountains[b].pos_y-100,
                 mountains[b].pos_x+300,
                 mountains[b].pos_y+32);
    }
}
// Function to draw trees objects.
function drawTrees()
{
    for(var i = 0; i < trees_x.length; i++)
    {
        fill(139,69,19);
        rect(trees_x[i]-15,floorPos_y-86,30,85);
        fill(50,205,50);
        ellipse(trees_x[i]-15,floorPos_y-52,40,40);
        ellipse(trees_x[i]+15,floorPos_y-52,40,40);
        ellipse(trees_x[i],floorPos_y-52,40,40);
        ellipse(trees_x[i]-30,floorPos_y-72,40,40);
        ellipse(trees_x[i]-25,floorPos_y-92,40,40);
        ellipse(trees_x[i],floorPos_y-112,50,40);
        ellipse(trees_x[i]+30,floorPos_y-72,40,40);
        ellipse(trees_x[i]+25,floorPos_y-92,40,40);
        ellipse(trees_x[i],floorPos_y-82,40,40);
    }
}

function liveCount()
{
    for (var i = 0; i < 4; i++)
    {
        textSize(30);
        if (i >= lives)
        {
            text(" ", 40, 120 + 50 * i)
        }
        else
        {
            text("💕", 40, 120 + 50 * i)
        }
    }
}
// ---------------------------------
// Canyon render and check functions
// ---------------------------------

// Function to draw canyon objects.

function drawCanyon(t_canyon)
{
    fill(0)
    rect(t_canyon.x_pos,432,t_canyon.width,145);
    fill(0,255,255);
    rect(t_canyon.x_pos,432,t_canyon.width,145);
    triangle(210,432,210,600,200,550)
    fill(205,133,63);

    fill(255);
    textSize(11);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+28);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+48);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+68);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+88);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+108);
    text("~~~~~~~~~", t_canyon.x_pos+30, floorPos_y+128); 
}

// Function to check character is over a canyon.

function checkCanyon(t_canyon)
{
    if(gameChar_world_x > t_canyon.x_pos && gameChar_world_x < t_canyon.x_pos + t_canyon.width && gameChar_y >= floorPos_y)
        {
            isPlummeting = true;
        } 
}

// ----------------------------------
// Collectable items render and check functions
// ----------------------------------

// Function to draw collectable objects.

function drawCollectable(t_collectable)
{
    if(t_collectable.isFound == false)
    {
    stroke(0);
    strokeWeight(1.5);
    fill(255,215,0);
    ellipse(t_collectable.x_pos,t_collectable.y_pos,t_collectable.size-10,t_collectable.size-10);
    ellipse(t_collectable.x_pos,t_collectable.y_pos,t_collectable.size-40,t_collectable.size-40) 
    }
}



// Function to check character has collected an item.


function checkCollectable(t_collectable)
{
    var d = dist(gameChar_world_x, gameChar_y, t_collectable.x_pos, t_collectable.y_pos);
   
    if (d < 30)
    {
        t_collectable.isFound = true;
        game_score +=1 ;
        scoreCollectedSound.play();
    }
}

function drawFlagpole(t_flagpole)
{
    push();
    strokeWeight(15);
    stroke(0);
    line(t_flagpole.x_pos, floorPos_y, t_flagpole.x_pos, floorPos_y - flagpole.height);
    pop();
    
    if(t_flagpole.isReached)
    {
        fill(255,0,0);
        rect(t_flagpole.x_pos, floorPos_y - flagpole.height, 50,80);
    }
}

function checkFlagpole(t_flagpole)
{
    if(dist(gameChar_world_x, 0, flagpole.x_pos, 0) < 20)
    {
        levelCompleteSound.play();
        t_flagpole.isReached = true;
    }
}

function createPlatform(x,y,length)
{
    var p = {
        x: x,
        y: y,
        length: length,
        draw: function()
        {
            fill(255,182,193);
            stroke(0);
            strokeWeight(1.5);
            rect(this.x, this.y, this.length, 20);
        },
        
        checkContact: function(check_x, check_y)
        {
            //checks if the gameChar is incontact with the platform
            
            if(check_x > this.x && check_x < this.x + this.length)
            {
                var d = this.y - check_y;
                if(d >= 0 && d < 5)
                {
//                   console.log("in bounds"); 
                    return true;
                }
                
            }
            
            return false;
        }
    }
    
    return p;
}
function Enemy(x,y,range)
{
    this.x = x;
    this.y = y;
    this.range = range;
    this.current_x = x;
    this.incr = 1;
    
    this.draw = function()
    {
        fill(255,0,0);
        ellipse(this.current_x+10, this.y - 25, 50);
        stroke(0)
        fill(0,255,0);
        ellipse(this.current_x - 5, this.y - 25, 5);
        ellipse(this.current_x + 5, this.y - 25, 5);
        stroke(0);
        line(
            this.current_x - 15,
            this.y - 35,
            this.current_x - 5,
            this.y - 30
        )
        line(
            this.current_x + 15,
            this.y - 35,
            this.current_x + 5,
            this.y - 30
        )
    }
    

    this.update = function()
    {
        this.current_x += this.incr;
        if(this.current_x <= this.x)
        {
            this.incr = 1;
        }
        else if(this.current_x > this.x + this.range)
        {
            this.incr = -1;
        }
    }
    
    
    
    this.isContact = function(gc_x, gc_y)
    {
        //returns true if contact is made
        var d = dist(gc_x, gc_y, this.current_x, this.y);
        
        if(d < 25)
        {
            return true;
        }
        
        return false;
    }
    
}

function gameScoreBoard(){
    textSize(32);
    text("Score: " + game_score,10,30); 
}
