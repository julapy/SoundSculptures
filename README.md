Making Sound Sculptures in OpenFrameworks

Audio Input from Microphone.

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