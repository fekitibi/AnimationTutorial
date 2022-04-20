#ifndef _H_TRACK_
#define _H_TRACK_

#include "vec3.h"
#include "quat.h"
#include "Frame.h"
#include "Interpolation.h"

#include<vector>

template<typename T, int N>
class Track {
protected:
	std::vector<Frame<N>> mFrames;
	Interpolation mInterpolation;
public:
	Track();
	void Resize(unsigned int size);
	unsigned int Size();
	Interpolation GetInterpolation();
	void SetInterpolation(Interpolation interp);
	float GetStartTime();
	float GetEndTime();
	// Sample the track at a given time
	T Sample(float time, bool looping);
	Frame<N>& operator[](unsigned int index);
protected:
	// Helper functions for the different interpolation types
	T SampleConstant(float time, bool looping);
	T SampleLinear(float time, bool looping);
	T SampleCubic(float time, bool looping);
	// Helper function evaluating the Hermit Spline
	T Hermite(float time, const T& p1, const T& s1,
		const T& p2, const T& s2);
	// Get the frame index which is a frame before the specified given time
	int FrameIndex(float time, bool looping);
	// Helper function that adjust the time if it is outside of valid time
	float AdjustTimeToFitTrack(float t, bool loop);
	// Cast loat value to specific track type
	T Cast(float* value); // Will be specialized
};

typedef Track<float, 1> ScalarTrack;
typedef Track<vec3, 3> VectorTrack;
typedef Track<quat, 4> QuaternionTrack;

#endif