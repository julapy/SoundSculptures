# Making Sound Sculptures in OpenFrameworks

A bit of explanation of what this is about.

## Audio Input from Microphone.

The very first thing we need to learn when making anything react to audio in OpenFrameworks, is how to first receive audio data from the real world via a microphone or from an audio file and then how to translate that data into something that we can use.

##### Audio Input from Microphone example.

This OF example is available here,
[https://github.com/julapy/SoundSculptures/tree/master/01_audioInputFromMic](https://github.com/julapy/SoundSculptures/tree/master/01_audioInputFromMic)


````
int channelsOut = 0;
int channelsIn = 2;
int sampleRate = 44100;
int bufferSize = 256;
int numOfBuffers = 4;

soundStream.setup(this, channelsOut, channelsIn, sampleRate, bufferSize, numOfBuffers);
````

````
void ofApp::audioIn(float * input, int bufferSize, int nChannels) {
	for(int i = 0; i<bufferSize; i++) {
		samplesChannelL[i] = input[i * 2 + 0];
		samplesChannelR[i] = input[i * 2 + 1];
	}
}
````

## Fast Fourier Transforms (FFT)

Fast Fourier transform (FFT) is an algorithm which can be used to convert a singnal from a time domain to a frequency domain. In digital audio processing this is particularly handy as it makes it easier to analyse and visualise the audio.

The image below shows a raw audio signal from the previous OF example where the audio is plotted over the time domain. Using FFT the audio is transformed so that it can be plotted over the frequency domain, which gives us a spectrum analyser visualisation of the sound.

TODO - add image.

##### ofxFFT

https://github.com/julapy/ofxFFT

what does it do? performs fft and normalises values.
ofxFFTLive and ofxFFTFile

## Meshes (quick 101)

## Audio Mesh
