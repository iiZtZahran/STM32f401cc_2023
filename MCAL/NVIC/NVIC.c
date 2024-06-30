/********************************************************/
/* Author   : Mohamed Zahran  */
/* Version  : V01             */
/********************************************************/

#include <SERVICES/Bit_utils.h>
#include <SERVICES/Std_types.h>
#include <SERVICES/stm32f401cc.h>
#include <MCAL/NVIC/NVIC.h>
#include <MCAL/NVIC/NVIC_prv.h>


NVIC_ErrorStatus_t NVIC_EnableIRQ(Nvic_tenuIRQn Copy_enuIRQn) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index = (u8)Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit = (u8)Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else {
		/*CLR PENDING FLAG*/
		NVIC->NVIC_ICPR[Loc_u8Index] = NVIC_u32SET_MSK << Loc_u8Bit;
		/*SET INTERRUPT ENABLE*/
		NVIC->NVIC_ISER[Loc_u8Index] = (NVIC_u32SET_MSK << Loc_u8Bit);
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}

NVIC_ErrorStatus_t NVIC_DisableIRQ(Nvic_tenuIRQn Copy_enuIRQn) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index = (u8)Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit = (u8)Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else {
		/*CLR INTERRUPT ENABLE*/
		NVIC->NVIC_ICER[Loc_u8Index] = (NVIC_u32SET_MSK << Loc_u8Bit);
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}

NVIC_ErrorStatus_t NVIC_GetPendingIRQ(Nvic_tenuIRQn Copy_enuIRQn, pu8 Add_pu8Pending) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index = (u8)Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit = (u8)Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else if (Add_pu8Pending == NULL) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorNullPointer;
	} else {
		/*READ THE PENDING FLAG*/
		if (NVIC->NVIC_ISPR[Loc_u8Index] & (NVIC_u32SET_MSK << Loc_u8Bit)) {
			/*ASSIGN RESULT*/
			*Add_pu8Pending = NVIC_u8PENDING_ON;
		} else {
			/*ASSIGN RESULT*/
			*Add_pu8Pending = NVIC_u8PENDING_OFF;
		}
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


NVIC_ErrorStatus_t NVIC_SetPendingIRQ(Nvic_tenuIRQn Copy_enuIRQn) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index =(u8) Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit =(u8) Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else {
		/*SET PENDING FLAG*/
		NVIC->NVIC_ISPR[Loc_u8Index] = NVIC_u32SET_MSK << Loc_u8Bit;
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


NVIC_ErrorStatus_t NVIC_ClearPendingIRQ(Nvic_tenuIRQn Copy_enuIRQn) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index = (u8)Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit = (u8)Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else {
		/*CLR PENDING FLAG*/
		NVIC->NVIC_ICPR[Loc_u8Index] = NVIC_u32SET_MSK << Loc_u8Bit;
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


NVIC_ErrorStatus_t NVIC_GetActive(Nvic_tenuIRQn Copy_enuIRQn, pu8 Add_pu8Active) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*DEFINE VARIABLE TO CALCULATE INDEX*/
	u8 Loc_u8Index = (u8)Copy_enuIRQn / NVIC_u8REGISTER_SIZE;
	/*DEFINE VARIABLE TO CALCULATE BIT*/
	u8 Loc_u8Bit = (u8)Copy_enuIRQn % NVIC_u8REGISTER_SIZE;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else if (Add_pu8Active == NULL) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorNullPointer;
	} else {
		/*RAED ACTIVE BIT*/
		if (NVIC->NVIC_IABR[Loc_u8Index] & (NVIC_u32SET_MSK << Loc_u8Bit)) {
			/*ASSIGN RESULT*/
			*Add_pu8Active = NVIC_u8PENDING_ON;
		} else {
			/*ASSIGN RESULT*/
			*Add_pu8Active = NVIC_u8PENDING_OFF;
		}
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


NVIC_ErrorStatus_t NVIC_SetPriority(Nvic_tenuIRQn Copy_enuIRQn, u8 Copy_u8Priority) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else {
		/*SET PERIORITY*/
		NVIC->NVIC_IPR[Copy_enuIRQn] = Copy_u8Priority & NVIC_u8PRIORITY_MSK;
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


NVIC_ErrorStatus_t NVIC_GetPriority(Nvic_tenuIRQn Copy_enuIRQn, pu8 Add_pu8Priority) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/*VALIDATE IRQ NUMBER*/
	if ((u8)Copy_enuIRQn >= NVIC_u8NUMBER_OF_IRQ) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorIRQNumber;
	} else if (Add_pu8Priority == NULL) {
		/*ASSIGN ERROR*/
		Loc_enuReturnStatus = NVIC_enuErrorNullPointer;
	} else {
		/*READ PERIORITY*/
		*Add_pu8Priority = NVIC->NVIC_IPR[Copy_enuIRQn];
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}


u32 getEncodingPriority(u8 Number_of_Sub_Group, u8 Sub_Group_Priority,
		u8 PreemptionPeriority) {
	/*DECLARE RETURN VARIABLE*/
	u32 Loc_ReturnPriority = 0;
	/*VALIDATE FOR SUB GROUP*/
	if (Number_of_Sub_Group > 4) {
		Loc_ReturnPriority = NVIC_u32PRIORITY_ERROR_MSK;
	} else {
		/*ASSING SUB-GROUP*/
		Loc_ReturnPriority |= (u32) Sub_Group_Priority
				<< NVIC_u8PRIORITY_START_BIT;
		/*VALIDATE FOR SUB-GROUP*/
		if (Loc_ReturnPriority
				& (NVIC_u32PRIORITY_CLR_MSK << (4 + Number_of_Sub_Group))) {
			Loc_ReturnPriority = NVIC_u32PRIORITY_ERROR_MSK;
		} else {
			/*ASSIGN PREEMPTIVE PERIORITY*/
			Loc_ReturnPriority |= (u32) PreemptionPeriority
					<< (4 + Number_of_Sub_Group);
		}
		/*VALIDATE THE PREEMPTIVE PERIORITY*/
		if (Loc_ReturnPriority & (NVIC_u32PRIORITY_CLR_MSK << 8)) {
			Loc_ReturnPriority = NVIC_u32PRIORITY_ERROR_MSK;
		}

	}
	/*RETURN ENCODED PERIORITY*/
	return Loc_ReturnPriority;
}

NVIC_ErrorStatus_t NVIC_setSubGroup(u32 Copy_u32SubGroup) {
	/*DEFINE ERROR STATUS VARIABLE*/
	NVIC_ErrorStatus_t Loc_enuReturnStatus = NVIC_enuOk;
	/* VALIDATE THE SUBGROUP */
	if (Copy_u32SubGroup & AIRCR_SUBGROUP_VLDATE_MSK) {
		Loc_enuReturnStatus = NVIC_enuErrorSubGroup;
	} else {
		/*ASSIGN THE SUB-GROUP*/
		AISCR &= AIRCR_SUBGROUP_CLR_MSK;
		AISCR |= Copy_u32SubGroup;
	}
	/*RETURN ERROR STATUS*/
	return Loc_enuReturnStatus;
}
