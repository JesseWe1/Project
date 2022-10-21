var song
var img
var fft //create a global variable
var particles = [] //create an array

function preload() {
  //preload the audio and the background picture
  song = loadSound('Risky Business.mp3')
  img = loadImage('background.jpg')
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  angleMode(DEGREES) //change the angleMode from radians to degrees
  imageMode(CENTER) //make the image to center
  rectMode(CENTER) //make the rect to center
  fft = new p5.FFT(0.3) //store the fft object in the global variable
  //background img
  img.filter(BLUR, 1)

  noLoop()
}

function draw() {
  background(0)
  
  //place the wave in the center of the canvas
  translate(width / 2, height / 2)

  //call the analyze first
  fft.analyze()
  //create beat detection which respond to the beat that 20-200 amp    
  amp = fft.getEnergy(20, 200)

  push()
  
  //make the background rotate
  if (amp > 230) {
    rotate(random(-0.5, 0.5))
  }
  //make the image larger to not see the angle when it rotates
  image(img, 0, 0, width + 100, height + 100)
  pop()

  //using an alpha layer, a black rect with transparency that change depending one the size of amp
  var alpha = map(amp, 0, 255, 180, 150)
  fill(0, alpha)
  noStroke() 
  rect(0, 0, width, height)

  
  stroke(255) //set the stroke to white
  strokeWeight(3) //set the strokeweight to be thicker to make it easy to see
  noFill()

  var wave = fft.waveform() //create waveform analysis
  
  //create a for loop that runs twice where the for loop variable is nagetive one the first time and positive one the second time, this create the 2 half circles which are mirrored
  for (var t = -1; t <= 1; t += 2) {
    beginShape()
    //create a for loop that iterates from zero to 180(which is the number of degrees of a half circle, I made two half circle so they are mirrored)
    for (var i = 0; i <= 180; i += 0.5) {
        
      //create an index that maps the for loop variable to the index of the wave
      // the index should be integer so floor it
      var index = floor(map(i, 0, 180, 0, wave.length - 1)) 
      
        
      //use index to map the radius
      var r = map(wave[index], -1, 1, 150, 350)
     
      //minimum and maximum radius of the circle
      var x = r * sin(i) * t
      var y = r * cos(i)
      vertex(x, y)
    }
    endShape()
  }
  
  //draw particle every frame
  var p = new Particle()
  particles.push(p)//push the particle into the array

 //call the show method to actually see the particles on canvas
  for (var i = particles.length - 1; i >= 0; i--) {
    if (!particles[i].edges()) {
      particles[i].update(amp > 230)//condition when amp > 230 the particles appear
      particles[i].show()
    } else {
      particles.splice(i, 1)
    }
    
  }
  
}

function mouseClicked() {
  if (song.isPlaying()) {
    song.pause()
    noLoop()
  } else {
    song.play()
    loop()
  }
}

//create particles around the circle
class Particle {
  constructor() {
    //define the position of the particle as a vector using the p5 vector.random2D
    this.pos = p5.Vector.random2D().mult(250)
    //velocity
    this.vel = createVector(0, 0)
    //acceleration
    this.acc = this.pos.copy().mult(random(0.0001, 0.00001))
      
    //control the size of the particles
    this.w = random(3, 5)

    //change the color randomly
    this.color = [random(200, 255), random(200, 255), random(200, 255),]
  }
    //update the position of particles
  update(cond) {
    this.vel.add(this.acc)
    this.pos.add(this.vel)
    if (cond) {
      this.pos.add(this.vel)
      this.pos.add(this.vel)
      this.pos.add(this.vel)
    }
  }
    //remove the particles that move out the canvas
  edges() {
    if (this.pos.x < -width / 2 || this.pos.x > width / 2 || this.pos.y < -height / 2 || this.pos.y > height / 2) {
      return true
    } else {
      return false
    }
  }
    
  show() {
    noStroke()
    fill(this.color)
    ellipse(this.pos.x, this.pos.y, this.w)
  }
}
