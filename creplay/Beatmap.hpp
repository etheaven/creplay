#pragma once
#include "stdafx.h"
#include "StringManipulation.hpp"
#include "Vector.hpp"
#include "Logs.h"

struct HitObject_t {
	int StartTime;
	int EndTime;
	NoteType_t Type;
	vector2f_t StartPoint;
	bool IsSlider;
	bool IsSpiner;
};

struct TimingPoint_t {

	float BeatLength;
	int Time;
};

// This is the worst code you could ever seen, but I'm too lazy to rewrite it.
class CBeatmap {
public:
	CBeatmap( ) {
	};

	~CBeatmap( ) {
	};
	// parse the file given by osu! beatmap standarts.
	void ReadFile( std::string );

#ifdef _DEBUG
	void Debug_printhitobj( ) {
		int iCount = 0;
		std::cout << "aaa\n";
		std::cout << m_fCircleSize << std::endl;

		for ( const  auto& x : m_vecHitObjects) {
			std::cout << x.StartTime << '\n';
			std::cout << x.EndTime << '\n';
			std::cout << x.Type << '\n';
		}
	}
#endif
protected:
	int m_iFileFormat;
	float m_fBeatLength;
	float m_fBeatLengthBase;
	float m_fCircleSize;
	float m_fOverallDifficulty;
	float m_fSliderMultiplier;
	float m_fApproachRate;
	float m_fHealthDrain;
	OsuGameModes_t m_Mode;
private:
	std::vector< std::string > m_vec_strLines;
	std::vector< HitObject_t > m_vecHitObjects;
	std::vector< TimingPoint_t > m_vecTimingObjects;
	std::string m_strBeatmapFile;
};