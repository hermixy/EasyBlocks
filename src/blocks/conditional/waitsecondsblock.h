#ifndef WAITSECONDSBLOCK_H
#define WAITSECONDSBLOCK_H

#include "../../statementblock.h"
#include "../../expressionblock.h"

/**
 * @brief The WaitSecondsBlock class
 *
 * @author Brecht Vandevoort
 */
class WaitSecondsBlock : public StatementBlock
{
public:
    /**
     * @brief Constructor
     */
    WaitSecondsBlock() : _seconds(NULL) {}

    /**
     * @brief Destructor
     */
    virtual ~WaitSecondsBlock();

    /**
     * @brief Returns a unique id of the block
     * @return A unique id specific to the block
     */
    virtual QString getId() const {return QString("Control_WaitSecondsBlock");}

    /**
     * @brief Returns a list of the paramtypes of the parameters
     * @return A QList<ParamType> containing the paramtype if each parameter
     */
    virtual QList<ParamType> getParamTypes() const;

    /**
     * @brief Returns the number of bodies of the block
     * @return The number of bodies of the block
     */
    virtual int getNumBodies() const {return 0;}

    /**
     * @brief Returns a description of the parameters
     * @return A description of the parameters
     */
    virtual QString getParamDescription() const {return QObject::tr("Wait") + QString(" %p ") + QObject::tr("seconds");}

    /**
     * @brief Returns a description of the bodies
     * @return A description of the bodies
     */
    virtual QString getBodiesDescription() const {return QString();}

    /**
     * @brief Executes the next step of the block. This function is assumed to do an atomic step in execution, and may not execute infinitely
     * @param executionThread The ExecutionThread this block is running on
     */
    virtual void executeNextStep(ExecutionThread& executionThread) const;

    /**
     * @brief Adds a parameterBlock to this Block
     * @param parameter The block to add
     * @param index The index of the parameter
     * @return True if adding succeeded , false if not
     */
    virtual bool addParameter(Block* parameter, int index);

    /**
     * @brief Adds a body to this block
     * @param body The block to add
     * @param index The index of the body
     * @return True if adding succeeded, false if not
     */
    virtual bool addBody(StatementBlock* body, int index) {return false;}

    /**
     * @brief Creates a new instance of the block and returns it
     * @return A new instance of the block
     */
    virtual Block* newInstance() const {return new WaitSecondsBlock();}

private:
    ExpressionBlock* _seconds;
};

#endif // WAITSECONDSBLOCK_H
