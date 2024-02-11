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

sENSTATE :: Stream (Float)
sENSTATE = extern "SENSTATE" Nothing

sTATE :: Stream (Float)
sTATE = extern "STATE" Nothing

apfail :: Stream (Bool)
apfail = extern "apfail" Nothing

good :: Stream (Bool)
good = extern "good" Nothing

limits :: Stream (Bool)
limits = extern "limits" Nothing

pullup :: Stream (Bool)
pullup = extern "pullup" Nothing

request :: Stream (Bool)
request = extern "request" Nothing

senstate :: Stream (Float)
senstate = extern "senstate" Nothing

standby :: Stream (Bool)
standby = extern "standby" Nothing

state :: Stream (Float)
state = extern "state" Nothing

supported :: Stream (Bool)
supported = extern "supported" Nothing

ap_maneuver_state :: Stream (Float)
ap_maneuver_state = constant 2.0;

ap_nominal_state :: Stream (Float)
ap_nominal_state = constant 1.0;

ap_standby_state :: Stream (Float)
ap_standby_state = constant 3.0;

ap_transition_state :: Stream (Float)
ap_transition_state = constant 0.0;

sen_fault_state :: Stream (Float)
sen_fault_state = constant 2.0

sen_nominal_state :: Stream (Float)
sen_nominal_state = constant 0.0

sen_transition_state :: Stream (Float)
sen_transition_state = constant 1.0

-- | FSM-002
--   @
--   FSM shall always satisfy if (standby & state = ap_transition_state) then STATE = ap_standby_state
--   @
propFSM_002 :: Stream Bool
propFSM_002 = (PTLTL.alwaysBeen ((standby && (state == ap_transition_state)) ==> (sTATE == ap_standby_state)))

-- | FSM-005
--   @
--   FSM shall always satisfy if (state=ap_nominal_state & standby)  then STATE = ap_standby_state
--   @
propFSM_005 :: Stream Bool
propFSM_005 = (PTLTL.alwaysBeen (((state == ap_nominal_state) && standby) ==> (sTATE == ap_standby_state)))

-- | FSM-003
--   @
--   FSM shall always satisfy if (state = ap_transition_state & good & supported) then STATE = ap_nominal_state
--   @
propFSM_003 :: Stream Bool
propFSM_003 = (PTLTL.alwaysBeen ((((state == ap_transition_state) && good) && supported) ==> (sTATE == ap_nominal_state)))

-- | FSM-008
--   @
--    FSM shall always satisfy if (state = ap_standby_state & !standby) then STATE = ap_transition_state
--   @
propFSM_008 :: Stream Bool
propFSM_008 = (PTLTL.alwaysBeen (((state == ap_standby_state) && (not standby)) ==> (sTATE == ap_transition_state)))

-- | FSM-011
--   @
--   FSM shall always  satisfy if (senstate = sen_nominal_state & !request) then SENSTATE = sen_transition_state
--   @
propFSM_011 :: Stream Bool
propFSM_011 = (PTLTL.alwaysBeen (((senstate == sen_nominal_state) && (not request)) ==> (sENSTATE == sen_transition_state)))

-- | FSM-009
--   @
--   FSM shall always satisfy if (state = ap_standby_state & apfail ) then STATE = ap_maneuver_state
--   @
propFSM_009 :: Stream Bool
propFSM_009 = (PTLTL.alwaysBeen (((state == ap_standby_state) && apfail) ==> (sTATE == ap_maneuver_state)))

-- | FSM-012
--   @
--   FSM shall  always  satisfy if (senstate = sen_fault_state & !request & !limits) then SENSTATE = sen_transition_state
--   @
propFSM_012 :: Stream Bool
propFSM_012 = (PTLTL.alwaysBeen ((((senstate == sen_fault_state) && (not request)) && (not limits)) ==> (sENSTATE == sen_transition_state)))

-- | FSM-010
--   @
--   FSM shall always satisfy if (senstate = sen_nominal_state & limits) then SENSTATE = sen_fault_state
--   @
propFSM_010 :: Stream Bool
propFSM_010 = (PTLTL.alwaysBeen (((senstate == sen_nominal_state) && limits) ==> (sENSTATE == sen_fault_state)))

-- | FSM-013
--   @
--   FSM shall always satisfy if (senstate = sen_transition_state & request) then SENSTATE = sen_nominal_state
--   @
propFSM_013 :: Stream Bool
propFSM_013 = (PTLTL.alwaysBeen (((senstate == sen_transition_state) && request) ==> (sENSTATE == sen_nominal_state)))

-- | FSM-007
--   @
--   FSM shall always satisfy if (state = ap_maneuver_state & supported & good) then STATE = ap_transition_state
--   @
propFSM_007 :: Stream Bool
propFSM_007 = (PTLTL.alwaysBeen ((((state == ap_maneuver_state) && supported) && good) ==> (sTATE == ap_transition_state)))

-- | FSM-004
--   @
--   FSM shall always satisfy if (! good & state = ap_nominal_state) then STATE = ap_maneuver_state
--   @
propFSM_004 :: Stream Bool
propFSM_004 = (PTLTL.alwaysBeen (((not good) && (state == ap_nominal_state)) ==> (sTATE == ap_maneuver_state)))

-- | FSM-001
--   @
--   FSM  shall  always  satisfy if (limits & !standby & !apfail & supported) then pullup
--   @
propFSM_001 :: Stream Bool
propFSM_001 = (PTLTL.alwaysBeen ((((limits && (not standby)) && (not apfail)) && supported) ==> pullup))

-- | FSM-006
--   @
--   FSM shall always satisfy if (state = ap_maneuver_state & standby & good) then STATE = ap_standby_state
--   @
propFSM_006 :: Stream Bool
propFSM_006 = (PTLTL.alwaysBeen ((((state == ap_maneuver_state) && standby) && good) ==> (sTATE == ap_standby_state)))


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
  trigger "handlerFSM-002" (not propFSM_002) []
  trigger "handlerFSM-005" (not propFSM_005) []
  trigger "handlerFSM-003" (not propFSM_003) []
  trigger "handlerFSM-008" (not propFSM_008) []
  trigger "handlerFSM-011" (not propFSM_011) []
  trigger "handlerFSM-009" (not propFSM_009) []
  trigger "handlerFSM-012" (not propFSM_012) []
  trigger "handlerFSM-010" (not propFSM_010) []
  trigger "handlerFSM-013" (not propFSM_013) []
  trigger "handlerFSM-007" (not propFSM_007) []
  trigger "handlerFSM-004" (not propFSM_004) []
  trigger "handlerFSM-001" (not propFSM_001) []
  trigger "handlerFSM-006" (not propFSM_006) []


main :: IO ()
main = reify spec >>= compile "fret"

