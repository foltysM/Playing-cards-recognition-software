<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<div>
<h3 align="center">Playing cards recognition software</h3>

  <p align="center">
    Playing cards recognition software. Made for traditional, 52 cards decks. For image given, outputs symbols recognised.
    <br />
    <a href="https://github.com/foltysM/Playing-cards-recognition-software"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/foltysM/Playing-cards-recognition-software">View Demo</a>
    ·
    <a href="https://github.com/foltysM/Playing-cards-recognition-software/issues">Report Bug</a>
    ·
    <a href="https://github.com/foltysM/Playing-cards-recognition-software/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#key-functions">Key functions</a></li>
        <li><a href="#built-with">Built With</a></li>
        <li><a href="#tests">Tests</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation and usage">Installation and usage</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

After providing the input file or choosing one of the built-in test images, process starts. Flow diagram is attached below.
<p align="center">
<img src="images/diagram.png" class="centerAlign" style="width:20%">

</p>


### Key functions
* fillRectangle function fills card inner rectangle with white. It is called only when number of contours exceeds 50 - it's Jack, Queen or King.
Area of maximal fitting rectangle is calculated for every contour. Last but not list biggest contour is filled with white using fillPoly function.

![queen1]

* isRed function checks whether the card has black or red symbol. Original image is converted to HSV, then thresholding is made. As the next step, erosion is applied. Further, software searches for contours. If area of any exceeds 200, card contains red symbol. Below, image after thresholding can be seen

![queen2]

* findTemplate finds model contour on pre-prepared image. Image is scaled down and converted to grayscale. Next steps are similar to contours matching on test images. Returns the larges contour found.

![two]

### Tests
* Test 1

![test1]

The output (Karo means Diamonds in Polish):

![output1]

* Test 2

![test2]

The output (Kier means Hearts in Polish):

![output2]

* Test 3

![test3]

The output (Trefl means Clubs in Polish):

![output3]
* Test 4

![test4]

The output (Karo means Diamonds in Polish):

![output4]
* Test 5

![test5]

The output (Pik means Spades in Polish):

![output5]


<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [C++](https://isocpp.org/)
* [Visual Studio](https://visualstudio.microsoft.com/)
* [OpenCV](https://opencv.org/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is how to run the software on your PC. </br >
To get a local copy up and running follow these simple example steps.


### Installation and usage

1. Clone the repo
   ```commandline
   git clone https://github.com/foltysM/Playing-cards-recognition-software
   ```
2. Install all necessary external references for OpenCV.
3. Run program

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- ROADMAP -->
## Roadmap

- [x] Finding symbol models
- [x] Recognizing card color
- [x] Working for all 13 types of cards
- [x] Accuracy > 90%


See the [open issues](https://github.com/foltysM/Playing-cards-recognition-software/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>




<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Best-README-Template](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#top">back to top</a>)</p>






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/foltysM/Playing-cards-recognition-software.svg?style=for-the-badge
[contributors-url]: https://github.com/foltysM/Playing-cards-recognition-software/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/foltysM/Playing-cards-recognition-software.svg?style=for-the-badge
[forks-url]: https://github.com/foltysM/Playing-cards-recognition-software/network/members
[stars-shield]: https://img.shields.io/github/stars/foltysM/Playing-cards-recognition-software.svg?style=for-the-badge
[stars-url]: https://github.com/foltysM/Playing-cards-recognition-software/stargazers
[issues-shield]: https://img.shields.io/github/issues/foltysM/Playing-cards-recognition-software.svg?style=for-the-badge
[issues-url]: https://github.com/foltysM/Playing-cards-recognition-software/issues
[license-shield]: https://img.shields.io/github/license/foltysM/Playing-cards-recognition-software.svg?style=for-the-badge
[license-url]: https://github.com/foltysM/Playing-cards-recognition-software/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/michalfoltys/
[test1]: images/test1.png
[test2]: images/test2.png
[test3]: images/test3.png
[test4]: images/test4.png
[test5]: images/test5.png
[output1]: images/output1.png
[output2]: images/output2.png
[output3]: images/output3.png
[output4]: images/output4.png
[output5]: images/output5.png
[queen1]: images/queen.png
[queen2]: images/red.png
[two]: images/two_template.png
[diagram]: images/diagram.png
