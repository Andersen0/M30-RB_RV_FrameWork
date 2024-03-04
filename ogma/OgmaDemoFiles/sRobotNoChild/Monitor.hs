import           Copilot.Compile.C99
import           Copilot.Language          hiding (prop)
import           Copilot.Language.Prelude
import           Copilot.Library.LTL       (next)
import           Copilot.Library.MTL       hiding (since, alwaysBeen, trigger)
import           Copilot.Library.PTLTL     (since, previous, alwaysBeen)
import qualified Copilot.Library.PTLTL     as PTLTL
import qualified Copilot.Library.MTL       as MTL
import           Language.Copilot          (reify)
import           Prelude                   hiding ((&&), (||), (++), (<=), (>=), (<), (>), (==), (/=), not)

classifier :: Stream (Int64)
classifier = extern "classifier" Nothing

distance_to_target :: Stream (Int64)
distance_to_target = extern "distance_to_target" Nothing

alert :: Stream (Bool)
alert = extern "alert" Nothing

pause :: Stream (Bool)
pause = extern "pause" Nothing

slowdown :: Stream (Bool)
slowdown = extern "slowdown" Nothing

state :: Stream (Int64)
state = extern "state" Nothing

turnoffUVC :: Stream (Bool)
turnoffUVC = extern "turnoffUVC" Nothing

dgt_14 :: Stream (Bool)
dgt_14 = distance_to_target > constant 14

dgt_21 :: Stream (Bool)
dgt_21 = distance_to_target > constant 21

dgt_7 :: Stream (Bool)
dgt_7 = distance_to_target > constant 7

-- | worker-state-req-001
--   @
--   While classifier=1 sRobot shall always satisfy (dgt_21 <=> state=0)
--   @
propWorker_state_req_001 :: Stream Bool
propWorker_state_req_001 = (PTLTL.alwaysBeen ((classifier == 1) ==> (dgt_21 == (state == 0))))

-- | dtt-assumption
--   @
--   The  sRobot  shall always satisfy  distance_to_target>=0 
--   @
propDtt_assumption :: Stream Bool
propDtt_assumption = (PTLTL.alwaysBeen (distance_to_target >= 0))

-- | adult-state-req001
--   @
--   While classifier=2 sRobot shall always satisfy (dgt_21 <=> state=0)
--   @
propAdult_state_req001 :: Stream Bool
propAdult_state_req001 = (PTLTL.alwaysBeen ((classifier == 2) ==> (dgt_21 == (state == 0))))

-- | adult-state-req002
--   @
--   While classifier=2 sRobot shall always satisfy (! dgt_21 & dgt_14 <=> state=2)
--   @
propAdult_state_req002 :: Stream Bool
propAdult_state_req002 = (PTLTL.alwaysBeen ((classifier == 2) ==> (((not dgt_21) && dgt_14) == (state == 2))))

-- | adult-state-req003
--   @
--   While classifier=2 sRobot shall always satisfy (! dgt_14 <=> state=3)
--   @
propAdult_state_req003 :: Stream Bool
propAdult_state_req003 = (PTLTL.alwaysBeen ((classifier == 2) ==> ((not dgt_14) == (state == 3))))

-- | worker-state-req-002
--   @
--   While classifier=1 sRobot shall always satisfy (! dgt_21 & dgt_14 <=> state=1)
--   @
propWorker_state_req_002 :: Stream Bool
propWorker_state_req_002 = (PTLTL.alwaysBeen ((classifier == 1) ==> (((not dgt_21) && dgt_14) == (state == 1))))

-- | worker-state-req-003
--   @
--   While classifier=1 sRobot shall always satisfy (! dgt_14 & dgt_7 <=> state=2) 
--   @
propWorker_state_req_003 :: Stream Bool
propWorker_state_req_003 = (PTLTL.alwaysBeen ((classifier == 1) ==> (((not dgt_14) && dgt_7) == (state == 2))))

-- | classifier-empty
--   @
--   While classifier=0 sRobot SHALL always satisfy (state=0)
--   @
propClassifier_empty :: Stream Bool
propClassifier_empty = (PTLTL.alwaysBeen ((classifier == 0) ==> (state == 0)))

-- | operationalstate-req004
--   @
--   While state = 3 sRobot shall ALWAYS satisfy (!slowdown & pause & alert & turnoffUVC)
--   @
propOperationalstate_req004 :: Stream Bool
propOperationalstate_req004 = (PTLTL.alwaysBeen ((state == 3) ==> ((((not slowdown) && pause) && alert) && turnoffUVC)))

-- | operationalstate-req001
--   @
--   While state = 0 sRobot shall ALWAYS satisfy (!slowdown & !pause & !alert & !turnoffUVC)
--   @
propOperationalstate_req001 :: Stream Bool
propOperationalstate_req001 = (PTLTL.alwaysBeen ((state == 0) ==> ((((not slowdown) && (not pause)) && (not alert)) && (not turnoffUVC))))

-- | operationalstate-req002
--   @
--   While state = 1 sRobot shall ALWAYS satisfy (slowdown & !pause & alert & !turnoffUVC)
--   @
propOperationalstate_req002 :: Stream Bool
propOperationalstate_req002 = (PTLTL.alwaysBeen ((state == 1) ==> (((slowdown && (not pause)) && alert) && (not turnoffUVC))))

-- | classifier-assumption
--   @
--   sRobot SHALL always satisfy classifier=0 xor classifier=1 xor classifier=2
--   @
propClassifier_assumption :: Stream Bool
propClassifier_assumption = (PTLTL.alwaysBeen (((classifier == 0) `xor` (classifier == 1)) `xor` (classifier == 2)))

-- | worker-state-req004
--   @
--   While classifier = 1 sRobot shall always satisfy (! dgt_7 <=> state=3)
--   @
propWorker_state_req004 :: Stream Bool
propWorker_state_req004 = (PTLTL.alwaysBeen ((classifier == 1) ==> ((not dgt_7) == (state == 3))))

-- | operationalstate-req003
--   @
--   While state = 2 sRobot shall ALWAYS satisfy (!slowdown & pause & alert & !turnoffUVC)
--   @
propOperationalstate_req003 :: Stream Bool
propOperationalstate_req003 = (PTLTL.alwaysBeen ((state == 2) ==> ((((not slowdown) && pause) && alert) && (not turnoffUVC))))


-- | Clock that increases in one-unit steps.
clock :: Stream Int64
clock = [0] ++ (clock + 1)


-- | First Time Point
ftp :: Stream Bool
ftp = [True] ++ false


pre :: Stream Bool -> Stream Bool
pre = ([False] ++)

tpre :: Stream Bool -> Stream Bool
tpre = ([True] ++)

-- | Complete specification. Calls the C function void  handler(); when
-- the property is violated.
spec :: Spec
spec = do
  trigger "handlerworker-state-req-001" (not propWorker_state_req_001) []
  trigger "handlerdtt_assumption" (not propDtt_assumption) []
  trigger "handleradult-state-req001" (not propAdult_state_req001) []
  trigger "handleradult-state-req002" (not propAdult_state_req002) []
  trigger "handleradult-state-req003" (not propAdult_state_req003) []
  trigger "handlerworker-state-req-002" (not propWorker_state_req_002) []
  trigger "handlerworker-state-req-003" (not propWorker_state_req_003) []
  trigger "handlerclassifier-empty" (not propClassifier_empty) []
  trigger "handleroperationalstate-req004" (not propOperationalstate_req004) []
  trigger "handleroperationalstate-req001" (not propOperationalstate_req001) []
  trigger "handleroperationalstate-req002" (not propOperationalstate_req002) []
  trigger "handlerclassifier_assumption" (not propClassifier_assumption) []
  trigger "handlerworker-state-req004" (not propWorker_state_req004) []
  trigger "handleroperationalstate-req003" (not propOperationalstate_req003) []


main :: IO ()
main = reify spec >>= compile "fret"

