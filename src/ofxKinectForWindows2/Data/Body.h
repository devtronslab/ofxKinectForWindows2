#pragma once

#include "Joint.h"

#include <Kinect.h>

namespace ofxKinectForWindows2 {
	namespace Data {
		class Body {
		public:
			int bodyId;
			int trackingId;
			bool tracked;
			HandState leftHandState;
			HandState rightHandState;
			TrackingConfidence leftHandConfidence;
			TrackingConfidence rightHandConfidence;
			std::map<JointType, Joint> joints;
			std::map<JointType, Joint> previousJoints;
			std::map<JointType, ofVec3f> distanceTraveled;
			std::map<Activity, DetectionResult> activity;

			void drawWorld();
			void clear();

			static const std::vector<pair<JointType, JointType> > & getBonesAtlas();
			map<JointType, ofVec3f> getJointVels(float elapsedTime);

		protected:
			static void initBonesAtlas();
			static vector<pair<JointType, JointType> > * bonesAtlas;
		};
	}
}