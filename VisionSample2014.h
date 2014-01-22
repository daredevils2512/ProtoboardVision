#include "WPILib.h"
#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"
#include "Math.h"


class VisionSample2014 {
	
	public:
	//Structure to represent the scores for the various tests used for target identification
		struct Scores {
			double rectangularity;
			double aspectRatioVertical;
			double aspectRatioHorizontal;
		};
		struct TargetReport {
			int verticalIndex;
			int horizontalIndex;
			bool Hot;
			double totalScore;
			double leftScore;
			double rightScore;
			double tapeWidthScore;
			double verticalScore;
		};
	//Constructor
		VisionSample2014(void);
	//Methods
		bool ProcessImage(void);
		
		double ComputeDistance(BinaryImage *image, ParticleAnalysisReport *report);
		
		double ScoreAspectRatio(BinaryImage *image, ParticleAnalysisReport *report, bool vertical);
		
		bool ScoreCompare(Scores scores, bool vertical);
		
		double ScoreRectangularity(ParticleAnalysisReport *report);
		
		double RatioToScore(double ratio);
		
		bool HotOrNot(TargetReport target);
	
};
