
"use strict";

let MoveGroupResult = require('./MoveGroupResult.js');
let MoveGroupSequenceActionResult = require('./MoveGroupSequenceActionResult.js');
let PlaceActionFeedback = require('./PlaceActionFeedback.js');
let PickupGoal = require('./PickupGoal.js');
let ExecuteTrajectoryFeedback = require('./ExecuteTrajectoryFeedback.js');
let MoveGroupAction = require('./MoveGroupAction.js');
let PickupAction = require('./PickupAction.js');
let ExecuteTrajectoryAction = require('./ExecuteTrajectoryAction.js');
let MoveGroupActionResult = require('./MoveGroupActionResult.js');
let PlaceActionResult = require('./PlaceActionResult.js');
let PickupResult = require('./PickupResult.js');
let ExecuteTrajectoryActionResult = require('./ExecuteTrajectoryActionResult.js');
let MoveGroupFeedback = require('./MoveGroupFeedback.js');
let PlaceResult = require('./PlaceResult.js');
let ExecuteTrajectoryActionFeedback = require('./ExecuteTrajectoryActionFeedback.js');
let MoveGroupSequenceActionGoal = require('./MoveGroupSequenceActionGoal.js');
let MoveGroupSequenceResult = require('./MoveGroupSequenceResult.js');
let MoveGroupActionGoal = require('./MoveGroupActionGoal.js');
let PickupFeedback = require('./PickupFeedback.js');
let PickupActionGoal = require('./PickupActionGoal.js');
let PlaceGoal = require('./PlaceGoal.js');
let MoveGroupGoal = require('./MoveGroupGoal.js');
let PlaceAction = require('./PlaceAction.js');
let PickupActionResult = require('./PickupActionResult.js');
let PlaceFeedback = require('./PlaceFeedback.js');
let ExecuteTrajectoryActionGoal = require('./ExecuteTrajectoryActionGoal.js');
let MoveGroupActionFeedback = require('./MoveGroupActionFeedback.js');
let ExecuteTrajectoryResult = require('./ExecuteTrajectoryResult.js');
let MoveGroupSequenceActionFeedback = require('./MoveGroupSequenceActionFeedback.js');
let MoveGroupSequenceFeedback = require('./MoveGroupSequenceFeedback.js');
let PlaceActionGoal = require('./PlaceActionGoal.js');
let MoveGroupSequenceAction = require('./MoveGroupSequenceAction.js');
let ExecuteTrajectoryGoal = require('./ExecuteTrajectoryGoal.js');
let MoveGroupSequenceGoal = require('./MoveGroupSequenceGoal.js');
let PickupActionFeedback = require('./PickupActionFeedback.js');
let RobotTrajectory = require('./RobotTrajectory.js');
let LinkScale = require('./LinkScale.js');
let PlaceLocation = require('./PlaceLocation.js');
let ObjectColor = require('./ObjectColor.js');
let CollisionObject = require('./CollisionObject.js');
let CartesianPoint = require('./CartesianPoint.js');
let RobotState = require('./RobotState.js');
let TrajectoryConstraints = require('./TrajectoryConstraints.js');
let AllowedCollisionEntry = require('./AllowedCollisionEntry.js');
let PlannerInterfaceDescription = require('./PlannerInterfaceDescription.js');
let MoveItErrorCodes = require('./MoveItErrorCodes.js');
let AllowedCollisionMatrix = require('./AllowedCollisionMatrix.js');
let KinematicSolverInfo = require('./KinematicSolverInfo.js');
let MotionSequenceItem = require('./MotionSequenceItem.js');
let JointLimits = require('./JointLimits.js');
let GenericTrajectory = require('./GenericTrajectory.js');
let MotionSequenceRequest = require('./MotionSequenceRequest.js');
let BoundingVolume = require('./BoundingVolume.js');
let MotionPlanResponse = require('./MotionPlanResponse.js');
let MotionPlanRequest = require('./MotionPlanRequest.js');
let DisplayRobotState = require('./DisplayRobotState.js');
let CartesianTrajectory = require('./CartesianTrajectory.js');
let PositionConstraint = require('./PositionConstraint.js');
let GripperTranslation = require('./GripperTranslation.js');
let CartesianTrajectoryPoint = require('./CartesianTrajectoryPoint.js');
let PositionIKRequest = require('./PositionIKRequest.js');
let DisplayTrajectory = require('./DisplayTrajectory.js');
let PlanningScene = require('./PlanningScene.js');
let OrientedBoundingBox = require('./OrientedBoundingBox.js');
let PlannerParams = require('./PlannerParams.js');
let PlanningOptions = require('./PlanningOptions.js');
let Grasp = require('./Grasp.js');
let MotionPlanDetailedResponse = require('./MotionPlanDetailedResponse.js');
let WorkspaceParameters = require('./WorkspaceParameters.js');
let VisibilityConstraint = require('./VisibilityConstraint.js');
let JointConstraint = require('./JointConstraint.js');
let Constraints = require('./Constraints.js');
let CostSource = require('./CostSource.js');
let PlanningSceneComponents = require('./PlanningSceneComponents.js');
let PlanningSceneWorld = require('./PlanningSceneWorld.js');
let ConstraintEvalResult = require('./ConstraintEvalResult.js');
let LinkPadding = require('./LinkPadding.js');
let ContactInformation = require('./ContactInformation.js');
let OrientationConstraint = require('./OrientationConstraint.js');
let MotionSequenceResponse = require('./MotionSequenceResponse.js');
let AttachedCollisionObject = require('./AttachedCollisionObject.js');

module.exports = {
  MoveGroupResult: MoveGroupResult,
  MoveGroupSequenceActionResult: MoveGroupSequenceActionResult,
  PlaceActionFeedback: PlaceActionFeedback,
  PickupGoal: PickupGoal,
  ExecuteTrajectoryFeedback: ExecuteTrajectoryFeedback,
  MoveGroupAction: MoveGroupAction,
  PickupAction: PickupAction,
  ExecuteTrajectoryAction: ExecuteTrajectoryAction,
  MoveGroupActionResult: MoveGroupActionResult,
  PlaceActionResult: PlaceActionResult,
  PickupResult: PickupResult,
  ExecuteTrajectoryActionResult: ExecuteTrajectoryActionResult,
  MoveGroupFeedback: MoveGroupFeedback,
  PlaceResult: PlaceResult,
  ExecuteTrajectoryActionFeedback: ExecuteTrajectoryActionFeedback,
  MoveGroupSequenceActionGoal: MoveGroupSequenceActionGoal,
  MoveGroupSequenceResult: MoveGroupSequenceResult,
  MoveGroupActionGoal: MoveGroupActionGoal,
  PickupFeedback: PickupFeedback,
  PickupActionGoal: PickupActionGoal,
  PlaceGoal: PlaceGoal,
  MoveGroupGoal: MoveGroupGoal,
  PlaceAction: PlaceAction,
  PickupActionResult: PickupActionResult,
  PlaceFeedback: PlaceFeedback,
  ExecuteTrajectoryActionGoal: ExecuteTrajectoryActionGoal,
  MoveGroupActionFeedback: MoveGroupActionFeedback,
  ExecuteTrajectoryResult: ExecuteTrajectoryResult,
  MoveGroupSequenceActionFeedback: MoveGroupSequenceActionFeedback,
  MoveGroupSequenceFeedback: MoveGroupSequenceFeedback,
  PlaceActionGoal: PlaceActionGoal,
  MoveGroupSequenceAction: MoveGroupSequenceAction,
  ExecuteTrajectoryGoal: ExecuteTrajectoryGoal,
  MoveGroupSequenceGoal: MoveGroupSequenceGoal,
  PickupActionFeedback: PickupActionFeedback,
  RobotTrajectory: RobotTrajectory,
  LinkScale: LinkScale,
  PlaceLocation: PlaceLocation,
  ObjectColor: ObjectColor,
  CollisionObject: CollisionObject,
  CartesianPoint: CartesianPoint,
  RobotState: RobotState,
  TrajectoryConstraints: TrajectoryConstraints,
  AllowedCollisionEntry: AllowedCollisionEntry,
  PlannerInterfaceDescription: PlannerInterfaceDescription,
  MoveItErrorCodes: MoveItErrorCodes,
  AllowedCollisionMatrix: AllowedCollisionMatrix,
  KinematicSolverInfo: KinematicSolverInfo,
  MotionSequenceItem: MotionSequenceItem,
  JointLimits: JointLimits,
  GenericTrajectory: GenericTrajectory,
  MotionSequenceRequest: MotionSequenceRequest,
  BoundingVolume: BoundingVolume,
  MotionPlanResponse: MotionPlanResponse,
  MotionPlanRequest: MotionPlanRequest,
  DisplayRobotState: DisplayRobotState,
  CartesianTrajectory: CartesianTrajectory,
  PositionConstraint: PositionConstraint,
  GripperTranslation: GripperTranslation,
  CartesianTrajectoryPoint: CartesianTrajectoryPoint,
  PositionIKRequest: PositionIKRequest,
  DisplayTrajectory: DisplayTrajectory,
  PlanningScene: PlanningScene,
  OrientedBoundingBox: OrientedBoundingBox,
  PlannerParams: PlannerParams,
  PlanningOptions: PlanningOptions,
  Grasp: Grasp,
  MotionPlanDetailedResponse: MotionPlanDetailedResponse,
  WorkspaceParameters: WorkspaceParameters,
  VisibilityConstraint: VisibilityConstraint,
  JointConstraint: JointConstraint,
  Constraints: Constraints,
  CostSource: CostSource,
  PlanningSceneComponents: PlanningSceneComponents,
  PlanningSceneWorld: PlanningSceneWorld,
  ConstraintEvalResult: ConstraintEvalResult,
  LinkPadding: LinkPadding,
  ContactInformation: ContactInformation,
  OrientationConstraint: OrientationConstraint,
  MotionSequenceResponse: MotionSequenceResponse,
  AttachedCollisionObject: AttachedCollisionObject,
};
